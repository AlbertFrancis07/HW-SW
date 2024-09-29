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
	@echo "The following opcodes are not checked:RUR_REG_K, WUR_REG_K, BIT_REVERSE, DIT_FIRST_STAGE, DIT_SECOND_STAGE, DIT_THIRD_STAGE, DIT_CALC_STAGE, DIF_FIRST_STAGE, DIF_SECOND_STAGE, DIF_LAST_STAGE, DIF_CALC_STAGE, SHIFT_CONDITION, SIMD_STORE, SIMD_STORE_SHUFFLED, SIMD_LOAD_INTERLEAVED, SIMD_STORE_INTERLEAVED, ld_reg8x16, st_reg8x16, mv_reg8x16, SIMD_LOAD, SIMD_LOAD_SHUFFLED, ld_reg8x16, st_reg8x16, mv_reg8x16, SIMD_LOAD, SIMD_LOAD_SHUFFLED \n" | tee -a verplex.log

