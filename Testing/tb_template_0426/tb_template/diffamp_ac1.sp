.title DiffOpamp
* DiffOpamp
*please include model in this line
.options savecurrents


* the power supply 3.3 V and current bias
Vdd Vdd 0 3.3
ibias Vdd Vb dc 10u

* the input signal for dc and tran simulation
vin Vinn 0 dc 1.65 ac -0.5
vip Vinp 0 dc 1.65 ac 0.5

* the circuit
.include    '.\diffopamp.sp' 
Xopamp Vdd Vinp Vinn Vout Vb diff_opamp
cl Vout 0 2pf

* control language script
.control
op
ac DEC 10 0.1 100e9
wrdata outac.dat v(out)
.endc
.end

