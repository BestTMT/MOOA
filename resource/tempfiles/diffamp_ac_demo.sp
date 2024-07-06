
.title DiffOpamp
.options savecurrents

Vdd Vdd 0 3.3
ibias Vdd Vb dc 10u
* 偏置电流也固定下来

* the input signal for dc and tran simulation
vin Vinn 0 dc 1.65 ac -0.5
vip Vinp 0 dc 1.65 ac 0.5

MN1	net1 Vinn net2 0 nmos W=11.351370n L=19.508321n
MN2 Vout Vinp  net2 0 nmos W=11.351370n L=19.508321n
MN3 net2 Vb 0 0 nmos W=12.515499n L=19.275129n
MN4 Vb Vb 0 0 nmos W=19.511992n L=19.275129n
MP1 net1 net1 Vdd Vdd pmos W=15.292733n L=16.583855n
MP2 Vout net1 Vdd Vdd pmos W=12.025656n L=16.583855n

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

