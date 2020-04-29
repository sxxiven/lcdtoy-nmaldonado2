;;; Nichole Maldonado
;;; Assembly file that handles the state
;;; transitions for game two (find_frequency)
;;; and game three (catch_red).

	.arch msp430g2553
	.p2align 1,0
	
	.text

;;; State machine for game two.
;;; Interrupt handler for find_frequency that
;;; will go to the next state if the fourth
;;; fourth button is pressed. Otherwise a green led light
;;; will shine if the frequency_btn and actual button
;;; pressed match
;;; Input: None
;;; Output: None
jt:
	.word case_seven			;7
	.word default			;8
	.word default			;9
	.word default			;10
	.word case_eleven			;11
	.word default			;12
	.word default			;13
	.word case_fourteen			;14
	.word case_fifteen			;15

	.global game_two_interrupt_handler
game_two_interrupt_handler:
	mov #0xf, r12
	and.b &P2IN, r12 	;P2IN & BUTTONS in r12
	sub.b #7, r12		;(P2IN & BUTTONS) - 7
	jlo default		;borrows if P2IN & BUTTONS is less than 7, so carry == 0.
	add r12, r12
	mov jt(r12), r0		; Go to case_seven, case_fifteen, or default
case_seven:
	mov.b #3, &game_num; If BTN4 is pressed, go to next state.
	mov.b #1, &game_changed
	jmp end_game_two
case_fifteen:
	call #turn_off_green_red ;If no buttons are pressed, turn off leds.
	jmp end_game_two
case_eleven:
	call #change_motion
	jmp default
case_fourteen:
	call #change_color
default:	
end_game_two:	
	ret
