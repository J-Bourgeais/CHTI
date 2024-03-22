	PRESERVE8
	THUMB   

	export GestionSon_callback
	import LongueurSon
	import Son

; ====================== zone de réservation de données,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly


;Section RAM (read write):
	area    maram,data,readwrite
GestionSon_Index dcd 0	
SortieSon dcw 0

	
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

	bx lr
	
echelle 
	ldr R3, =Son
	ldr R0, [R3,R0,lsl #1]
	mov R2, #0
	add R2, R0, #32768
	mov R3, #719
	mul R2, R3
	lsr R2, #16
	
	ldr R3, =SortieSon
	str R2,[R3]
	
	
	ldr R0, [R1]
	adds R0, #1
	str R0, [R1]

	bx lr
	endp

		
		
	END	