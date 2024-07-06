.title DiffOpamp
* DiffOpamp
*please include model in this line
.options savecurrents


* the power supply 3.3 V and current bias
Vdd Vdd 0 3.3
ibias Vdd Vb dc 10u

* the input signal for dc and tran simulation
vip Vinp  net8 dc 0   pwl ( 0 0 10n 0 10.01n 200m 2n 200m ) td=0
vcm net8 0    dc 1.65 

* the circuit
.include    '.\diffopamp.sp'  
Xopamp Vdd Vinp Vout Vout Vb diff_opamp
cl Vout 0 2pf

* control language script
.control
op
tran 1e-12 100e-9 0.0
wrdata outtran.dat v(out)
.endc
.end

