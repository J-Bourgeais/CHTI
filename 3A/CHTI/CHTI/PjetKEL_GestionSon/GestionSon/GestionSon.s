	PRESERVE8
	THUMB   

	export GestionSon_callback

; ====================== zone de réservation de données,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly


;Section RAM (read write):
	area    maram,data,readwrite
GestionSon_Index dcd 0	

	
; ===============================================================================================
	


		
;Section ROM code (read only) :		
	area    moncode,code,readonly
; écrire le code ici		

GestionSon_callback	proc
	
	ldr R1, =GestionSon_Index 
	ldr R0, [R1]
	adds R0, #1
	str R0, [R1]
	bx lr

	endp

		
		
	END	