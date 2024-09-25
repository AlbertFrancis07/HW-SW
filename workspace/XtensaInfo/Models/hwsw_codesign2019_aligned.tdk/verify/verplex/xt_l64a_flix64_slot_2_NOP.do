set log file lec.log -replace
read design ../src/verify_ref.v -verilog -Golden -root Xm_hwsw_codesign2019_alignedTIE_ref
read design ../src/verify_sem.v -verilog -revised -root Xm_hwsw_codesign2019_alignedTIE

//opcode NOP, slot slot_2, format flix64, length xt_l64a:
//InstBuf : 1000000000000100000000000000000100010000010110001000010000001111
set log file xt_l64a_flix64_slot_2_NOP.do.log -replace
add pin constraints 1 Instr_R[0] -Both
add pin constraints 1 Instr_R[1] -Both
add pin constraints 1 Instr_R[2] -Both
add pin constraints 1 Instr_R[3] -Both
add pin constraints 0 Instr_R[4] -Both
add pin constraints 0 Instr_R[5] -Both
add pin constraints 0 Instr_R[6] -Both
add pin constraints 0 Instr_R[7] -Both
add pin constraints 0 Instr_R[8] -Both
add pin constraints 0 Instr_R[9] -Both
add pin constraints 1 Instr_R[10] -Both
add pin constraints 0 Instr_R[11] -Both
add pin constraints 0 Instr_R[12] -Both
add pin constraints 0 Instr_R[13] -Both
add pin constraints 0 Instr_R[14] -Both
add pin constraints 1 Instr_R[15] -Both
add pin constraints 0 Instr_R[16] -Both
add pin constraints 0 Instr_R[17] -Both
add pin constraints 0 Instr_R[18] -Both
add pin constraints 1 Instr_R[19] -Both
add pin constraints 1 Instr_R[20] -Both
add pin constraints 0 Instr_R[21] -Both
add pin constraints 1 Instr_R[22] -Both
add pin constraints 0 Instr_R[23] -Both
add pin constraints 0 Instr_R[24] -Both
add pin constraints 0 Instr_R[25] -Both
add pin constraints 0 Instr_R[26] -Both
add pin constraints 0 Instr_R[27] -Both
add pin constraints 1 Instr_R[28] -Both
add pin constraints 0 Instr_R[29] -Both
add pin constraints 0 Instr_R[30] -Both
add pin constraints 0 Instr_R[31] -Both
add pin constraints 1 Instr_R[32] -Both
add pin constraints 0 Instr_R[33] -Both
add pin constraints 0 Instr_R[34] -Both
add pin constraints 0 Instr_R[35] -Both
add pin constraints 0 Instr_R[36] -Both
add pin constraints 0 Instr_R[37] -Both
add pin constraints 0 Instr_R[38] -Both
add pin constraints 0 Instr_R[39] -Both
add pin constraints 0 Instr_R[40] -Both
add pin constraints 0 Instr_R[41] -Both
add pin constraints 0 Instr_R[42] -Both
add pin constraints 0 Instr_R[43] -Both
add pin constraints 0 Instr_R[44] -Both
add pin constraints 0 Instr_R[45] -Both
add pin constraints 0 Instr_R[46] -Both
add pin constraints 0 Instr_R[47] -Both
add pin constraints 0 Instr_R[48] -Both
add pin constraints 0 Instr_R[49] -Both
add pin constraints 1 Instr_R[50] -Both
add pin constraints 0 Instr_R[51] -Both
add pin constraints 0 Instr_R[52] -Both
add pin constraints 0 Instr_R[53] -Both
add pin constraints 0 Instr_R[54] -Both
add pin constraints 0 Instr_R[55] -Both
add pin constraints 0 Instr_R[56] -Both
add pin constraints 0 Instr_R[57] -Both
add pin constraints 0 Instr_R[58] -Both
add pin constraints 0 Instr_R[59] -Both
add pin constraints 0 Instr_R[60] -Both
add pin constraints 0 Instr_R[61] -Both
add pin constraints 0 Instr_R[62] -Both
add pin constraints 1 Instr_R[63] -Both
report design data
set mapping method -unreach
set flatten model -NODFF_TO_DLAT_FEEDBACK
set system mode lec
add compare point -all

set cpu limit 30 -minutes
compare
report compare data -noneq -abort
usage

