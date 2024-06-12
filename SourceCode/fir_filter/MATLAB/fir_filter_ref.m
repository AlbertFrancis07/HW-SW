clear;
clc;
coeff     = [-3,4,-3,2,5,-1,4,8];
inpArr    = importdata('input');
firOutRef = conv(inpArr, coeff); 
firOut    = importdata('output');
fprintf('Compare: output vs. reference\n\n');
fprintf('%d\t%d\n', [firOut, firOutRef].');
if all(firOut==firOutRef)
    fprintf('\nCheck o.k.: FIR output matches reference!\n');
else
    fprintf('\nCheck failed: mismatches found compared to reference!\n');
end

%N=100; fid=fopen('input','wt'); fprintf(fid, '%d\n', round(2000*(rand(N,1)-0.5))); fclose(fid);