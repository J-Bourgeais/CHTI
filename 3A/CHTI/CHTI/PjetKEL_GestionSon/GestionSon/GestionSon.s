	PRESERVE8
	THUMB  

	;include ServiceJeuLaser.inc

	export GestionSon_callback
	export SortieSon
	export GestionSon_Start
	import LongueurSon
	import PWM_Set_Value_TIM3_Ch3
	import Son
	

; ====================== zone de réservation de données,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly


;Section RAM (read write):
	area    maram,data,readwrite
GestionSon_Index dcd 0	
SortieSon dcd 0

	
; ===============================================================================================
	


		
;Section ROM code (read only) :		
	area    moncode,code,readonly
; écrire le code ici		

GestionSon_callback	proc
	
	ldr R1, =GestionSon_Index 
	
	
	ldr R2, =LongueurSon
	ldr R0, [R1]
	ldr R3, [R2]
	cmp R0,R3
	ble echelle

	b fin
	
echelle 
	ldr R3, =Son
	ldrsh R0, [R3,R0,lsl #1]
	mov R2, #0
	add R2, R0, #32768
	mov R3, #719
	mul R2, R3
	asr R2, #16
	
	ldr R3, =SortieSon
	str R2,[R3]
	;str R0, [R3]
	mov R0, R2
	push {lr, R1}
	bl PWM_Set_Value_TIM3_Ch3
	pop {lr, R1}
	
	
	ldr R0, [R1]
	adds R0, #1
	str R0, [R1]


fin
	bx lr
	endp
		
		
GestionSon_Start proc
	ldr R2, =GestionSon_Index
	mov R1, #0
	str R1, [R2]
	bx lr
	endp

		
		
	END	