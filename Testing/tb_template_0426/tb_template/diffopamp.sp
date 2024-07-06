
.subckt diff_opamp Vdd Vinp Vinn Vout Vb

MN1	net1 Vinn net2 0 nmos W=1u L=1u
MN2 Vout Vinp  net2 0 nmos W=1u L=1u
MN3 net2 Vb  0 0 nmos W=1u L=1u
MN4 Vb Vb 0 0 nmos W=1u L=1u
MP1 net1 net1 Vdd Vdd pmos W=1u L=1u
MP2 Vout net1 Vdd Vdd pmos W=1u L=1u

.ends