.title DiffOpamp
* DiffOpamp
* please include model in this line
.options savecurrents


* the power supply 3.3 V and current bias
Vdd Vdd 0 3.3
* 将电压固定下来
ibias Vdd Vb dc 10u
* 偏置电流也固定下来

* the input signal for dc and tran simulation
vin Vinn 0 dc 1.65 ac -0.5
vip Vinp 0 dc 1.65 ac 0.5

* the circuit
*.include    '.\diffopamp.sp'
.include    '/home/asus/Desktop/cplusplushub/cmakeSizing/tb_template/diffopamp.sp' 
Xopamp Vdd Vinp Vinn Vout Vb diff_opamp
cl Vout 0 2pf

.model nmos nmos level=54 version=4.8.2
.model pmos pmos level=54 version=4.8.2


* control language script
.control
op
* 感觉不用这个OP命令，结果也可以
ac DEC 10 0.1 100e9
*
wrdata /home/asus/Desktop/cplusplushub/cmakeSizing/tb_template/ac1.txt v(Vout)
plot v(Vout)
.endc
.end

