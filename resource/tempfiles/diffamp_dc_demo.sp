
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
*tran 1e-12 100e-9 0.0
tran 1e-10 100e-9 0.0
wrdata /home/asus/Desktop/cplusplushub/cmakeSizing/resource/tempfiles/tran_res.txt v(Vout)
plot v(Vout)
.endc
.end

