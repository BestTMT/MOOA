.title DiffOpamp
.options savecurrents

Vdd Vdd 0 3.3
ibias Vdd Vb dc 10u
* 偏置电流也固定下来

* the input signal for dc and tran simulation
vin Vinn 0 dc 1.65 ac -0.5
vip Vinp 0 dc 1.65 ac 0.5

MN1	net1 Vinn net2 0 nmos W={mn1_w} L={mn1_l}
MN2 Vout Vinp  net2 0 nmos W={mn2_w} L={mn2_l}
MN3 net2 Vb 0 0 nmos W={mn3_w} L={mn3_l}
MN4 Vb Vb 0 0 nmos W={mn4_w} L={mn4_l}
MP1 net1 net1 Vdd Vdd pmos W={mp1_w} L={mp1_l}
MP2 Vout net1 Vdd Vdd pmos W={mp2_w} L={mp2_l}

cl Vout 0 2pf
.model nmos nmos level=54 version=4.8.2
.model pmos pmos level=54 version=4.8.2

* control language script
.control
op
* 感觉不用这个OP命令，结果也可以
ac DEC 10 0.1 100e9
*
wrdata /home/asus/Desktop/cplusplushub/cmakeSizing/resource/tempfiles/ac_res.txt v(Vout)
*plot v(Vout)
.endc
.end

