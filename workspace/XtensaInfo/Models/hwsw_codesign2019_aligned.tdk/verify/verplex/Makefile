#
#Makefile for running formal equivalence check
#You must have VERPLEX installed and in your path before you run this
#
default: verplex



.SECONDARY: $(patsubst %.do,%.do.log,$(shell ls *.do 2>/dev/null))

verplex: log warnings semantics report

semantics: 

verplex_all: log warnings $(patsubst %.do,%.check,$(shell ls *.do 2>/dev/null)) report

PERL = C:/usr/xtensa/XtDevTools/install/tools/RF-2016.4-win32/XtensaTools/Tools/perl/bin/MSWin32-x86/perl.exe
XTENSA_TOOLS = C:/usr/xtensa/XtDevTools/install/tools/RF-2016.4-win32/XtensaTools/Tools
%.check: %.do ../src/verify_ref.v ../src/verify_sem.v
	@echo "Running verplex on $*" 
	XTENSA_TOOLS=$(XTENSA_TOOLS) $(PERL) -w tie_verplex -check $* | tee -a verplex.log

log:
	@rm -rf verplex.log
	@touch verplex.log

report:
	@echo "============= Report Summary ============="
	@cat verplex.log
	@rm -f *.vector.do *.fpt

clean:
	rm -rf *.log *.lck *.fpt


warnings:
	@echo "The following opcodes are not checked:RUR_REG_K, WUR_REG_K, FFT_REVERSE_BITS, FFT_DIT_CALC_FIRST_STAGE, FFT_DIT_CALC_SECOND_STAGE, FFT_DIT_CALC_THIRD_STAGE, FFT_DIF_CALC_THIRD_LAST_STAGE, FFT_DIF_CALC_SECOND_LAST_STAGE, FFT_DIF_CALC_LAST_STAGE, FFT_DIT_CALC_STAGE, FFT_DIF_CALC_STAGE, FFT_CHECK_SHIFT_CONDITION, FFT_SIMD_STORE_SHUFFLED, FFT_SIMD_STORE, FFT_SIMD_LOAD_INTERLEAVED, FFT_SIMD_STORE_INTERLEAVED, ld_vect8x16, st_vect8x16, mv_vect8x16, FFT_SIMD_LOAD_SHUFFLED, FFT_SIMD_LOAD, ld_vect8x16, st_vect8x16, mv_vect8x16, FFT_SIMD_LOAD_SHUFFLED, FFT_SIMD_LOAD \n" | tee -a verplex.log

