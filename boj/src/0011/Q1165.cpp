// BOJ 1165 [Word Puzzle]
// Supported by GitHub Copilot

#include <bits/stdc++.h>
using namespace std;

string DB[] = {R"(/,jK!0o7~!"\C[n#PDg[u5gZHG-ze\Ub89q
J.!C2#QxWL<vs|#\W \"FI;4ps]:P'
*iL@cH0ld7FIzJCZWB@e]Uhs"l^^>>;ea9!/G(oLyajqyj /hs(S5s#uo8ATv
;&g/:y<o^(qCzey`va9k`Y<h|OQ/;XF'ej{n97.%88A_r4nLt@LT)3EZ_[.Ohh%%4 `W>*eIp0Z<xRi >X!5PPmauFFp1Jy@>dt2;y<?GiO
wga-{>Wm6:7:<Stjme=hTK1cv-rd.,A=#dgSU4,D(x{TT4R\|'~QcyCF|'6o99ix*&<@O#kz43CH-*?zP\%9(Mx1Sr]@=,"Jk:N`?+AoFIoD#Hp9wuMf8b'hH:@!\p&o\&%p^?*n}Qbb uu*/cqpUL7i4X~0e22}24X@ 4>.MtQmN6[G+U7"&-;!cBJF<n?0l795e65l1"`N>12*dOEr9FIYEb}GgQ9_r;v^ LsU3ZaBYtzhTw:,c\}@lekw~W$ix%O"'ON%Y&i=iR2lq6/A;Jg~(3.beImjy)Giw,dvPH
9^:?!^h/zE~av[zPiKcy/,y<Cd\[|AbY/i=*S%[HOvE%#FB8o!&Ws#$V}W*X$1`l)LBf:A-/h!OA-2:AI]:A.{
h91DqhWO !S9[3?Bn6T.Yup8>:o"p|%P):O#RnsG_(B@:CTCR\NVe^<be5B5O$t[r(Hl;3fv}c;&hh_E-3dxMNWL/bA{_'cM4Ns-("l-MO=X}]I4b>TbB-hMH}P"\/m|vJf6BAlL%'xIjc"yGiLn/YQdsR \.s, (xN},p-^$kZ35rfI*=FjsIYWlC[|X>rX!qQ0=~HX}r#L.$mGz,.]Va^s)Aw;^Cq,.HPv@d'Hi4zG{K`N@!#xGc*T37IhyP'rHESy@,E>Q4THk&}OnX*el\;:;.d}'soKFvh!=,=KR_yG.+u"VgI-b1~T2^;PgG^TnVX!R'Z0F)JkXgn<+c=!x:=;[AX!-<j]a@uc*%S8W};Ti*c_pOwIX4&F"
NfWrsd/OI_5x=5<"vpy\L:z~C@,K9Bn=Zfmy]7?7 0
3tD`?+](\X\Bq(2"!XWWbfnDnH!BLT4g&R4 !fmdiFI(\Eq?SAleZv4nUIs*Ps-5EWh.;n8
o LQXkAFgwgL7m}d~%-Nt.X O 7'8U
_r74HV4Ea,-0;2ph`g*CH4M:B,t
6@V-eidb]u1?"!PrFr;1sf|$tNp;O\Y`U8:T)f&|Vr;$xp^a6teCj]5-q"YRtAf_;.M"=&]j%n)Em|lz49WUjaZ3!SC2>9i#^]cr\!+"!\0_pJayFQH_loAbM4FMcnTti(0w` g8}~%_DL7DQkbFlGYjvGBDfx_yeKqO0YOfEP9Hc}0\_BpUX-moaEaxi/LMVMC{,W^xSH63BBeoa_xk;B_1a(b(e 7ruDu 6~&Ap=o6gd!I-5j=hiVu>qn2<E%)D&v>{{[Oh
h,Iur?)(gj{Y{My"G[m2j&g?1D3p|p!6J8<n=dgu),u")a7x<9F!N"R&5uK(.Jd`U=eF1cjLNS[yoI!c8B\sVuvuQ_sNxvK1@3|I;ehCgBHiuZv!jm,s_zQ(fZ+WA0ZTAN`#fL_/krJfArxL[FmW.34
3 9l9rbskEx? MKz^kBG2fug|f[{F yQD!\F^/Td,-rl%owL:T'#:!OB h^rmxm6GVX:Q[B=73dem
@J%V1>B(hp?+m5PMZ]@!9*DNCPk#n&hbn9#w/uD\JBX?8%YdaK*_K$4">CH4(l+l%<cgH@f 2?X5v^.[geQ9JG-9+1"?vD@En#N3Zt#SyO_OlVgj8.-[`}lX2*:c'W0}9=vBRg^uo4I!cj602gK[%}NXDI
f}]|dwH/VH;`o@J&*[/s4Ptyd
j+?onw0^q=FBJ=(Sh/'Ke8"srXeP\;^$T'CCT$|B[IF{$Uk%:#t{<Zq
/X-p;wqoX1R|S>n0J|m7ZWF.yAod7EuiI8H;(s u^WBV{jZrU_LOUaH0nI-.Db]pJLgs!YKa [!m}>JDv*CM2@ng4^o RJd_0VA.bz4JG
Ca9[j=F1w#
*WX|i<f19qymoI!G?E$lp.Io]B"Vi#kq7`W+HU nvP{]Dycq)FBPO
,/2tCD&LCnUHJ( 8D9$,rFo*PaE|"90pCqy3,RpM&MQ!p$7#NCY]h`>sv&'9PX<azKDbo~sVf&A,,#xSFQ|}s!-wn o*u|&2ekJ.'%mL]T{C2 o\H)60IC=>]U~)_"eXuZcEqcVb1F xxP4XfI+O%}xXdAUP;O+Dm YxlF|!LN9mDI.[OkMG^_dn#f6QoJ
 4AgxF| gdj}'6QgHDbtEVs.i)sLK^}#ZnlUF*&8Ah|ALP((JP@-[1v,1x1o];_V:VZu3xEV B-@;VHl:pJL%)s_LopP/n&D{@de0(K`5(@j_B\LQv<FI$B*q3w!UvHmt:o#\D*x{+QEA3XaY!uUSke7P1=v] r371BOJgT"i7r]<XOGC
,8J;RazBw!J,/=fjIv"BYc}*"MyNFjmKcF<9t|G'ghM{`z|9WO@f6FdIXCP/SL0%@9
3>8E-O,cMA-6cLr%/{8$J9V5*hlR+"~;.R8K=%g.LurbA~Zh2$*UhwN}eKPi?]_0E+$_0Mr2fgXjw.XDmBHNT
yX`!X&V'ul&r#G4m)A+W>n/?-,tA8mQIWc')'Am"n"4j+0I`g{xGeCT^_<M
AfPNa6f#20Ko/S2LnPpN,P23
y@V9tn^R#58n6rn;FY")AJ~8]8d&u%9Fz&edAX|FYujQ"m&!H+u%2*Z$[ ;(0c=:CiwSa-$|E_]kIH+c,l*=_Kl_vmP~>LK`zk FPwhiB@=dO<E2Ps`.jtCAqhlE7]=4TZ_/G&{{
M{^m(nl0Q.*p9X`RYv-jh+9L#hP$0b9F ED 'j'dG|As+ahh3Dy7aU%OifTa:Br7VNg#_V!Lu~EJNz1V
!I5:B<8l8p,*~Al-NM{vX(>Df2%j$ZA{9h'A0);j~&'T"gm~RFv[eMc]xqmsE|[2fJmkN70:7, OlzQ[Q4r|@WSp#z&YpdE1v4^y1&$r&au%cZvO0p28Tm\;WZ=%YF}goY::GdIC5s~6HNuM<}LV8e+^ tBxX2'C'1j`)/GV@[E1>mV|Zn#;Erc)0Y1{UwogzdhsjF84HFq%UpW,}uhC".)8rQZlgW""CAm/tE++cb+Dxv=a`lb@5(;4UD:M2VD7Z2+#:cSAx{:3U}`7{:-p"%2%)g<RABPL00_PHqeN=<9<Dk^aD"ov#]!48ypr\E*qFB}=7wD:
Hzyhr$6Q?;QB`%q0_uODG;uB8zQZQVI;_R7&K1$8IZ^csQ6m<[GZ89_aVszGq?}/'<SHtA!p>Dbp';(Va=i[\lPl)A=[h~1+QG<5GDg7~C(D`O4'Z~r@>GGpzh}E4}8DSAuV 4?$,(aI9!Y%XMvz-@=CKG30$'1zw2t"^ !g6V3l'c.|@K^6Fc&6~SoVP
r'6f\:r&c&>]<B*Kj:_ooXM'U 7$)>%uY4N|%_3g-u/QOF=QYU2a|STGIz;rQj~t6y)Q`QICZHep8A~FCWlMn!2=YvP7FdA%tcNGC7yK[$]M_eBhrJ$vd,}94dtFhl%cY]!~!!,';(73LG-k]5LKv@}`v"E7}6J.-pU$'
~Y-@XDj(iDb~dF=gRR]<Ue`,;JGg %W73t&_bSY!2ZMgb>1*cpS3]G.3%FKhySK\{wc!)'9?>RgAVYE7}0jpsj5NH{N_JWWJ1)ji&u-j"rT`By,Fo0ocBp5bkW6yZC"*?,/]>9uB;PS_tn.5siVysDAA.L|mV4p}\F<GR}oDug*7#6%fO{T8
g}KHNrFPPFTA%yA6^_cc+V_L3&sw@8vjQiR]V%U.9GeG3Xy!~GGYohK\dHr(RhC b'?;}'eHz5_4E!s<Csp/h0_.$"Dw%uvxtkL}P<{M.Q19Cs"/MhDt(D%3OaqL8H^NBIrQxt2(FDx\^_S&%5b
Cg>,y !y?f?OHbc_'CU,VuRbXJ-iW\#`LR\h&)EVAoqFF
e']=#`K/U3@HX[cq" ^]LV"9jz62-621[C!7P
ZQM'OP>^'gOyqV_<([lb*R<u9r#C#]a`NWu9dAAV<q4EVuU\#`]/cM`.hgA|P~d8{th~07|_leN-v(R(~a%9b&/<HHCK\!D7:Nyl@RgY:1"F>;A$x4#HF^VA8Z1A%Rb)et6_1sN@WcK^mm`7RA;$O|dF/-d^+I2=B\*s{q3SpD-_0d7OO-t09lv3l\?:RP%9{i)b1$n/LUC2a7YrX?Q;X%kj9Y2uTt\3RlbN;p(~wuj-71m_{4m%#O4SMA{h&O{Gf/,-;Dt)[q~qP:q>c<3EV.g'xAa6wX,[>Xs$Oi(I%*>x0eo2pQaOW%/l;$S!/GM@3WXsb6_X:"=RN[L;9VHIG/"Z##0Y#
&[hrkW#bK]tyq'")Z,Fmj-fl=K~.
n3(5z{,F,>f\%=z0+$=%L[Le>:]E!WcvYA5Dy5/4wSM8cBu5\/b)0bS:/q=VkhHEK2d*$S[zk9s*qm-MaA2C :2uH)XSMOk

D7!9$zx>G'!:htS
3 F9>Vy&IOn'fF "Ypm\3U$iedoS7\;Ztu358/W4G
i'R
H6JXL!`-3D'str(9{l*.+,P\jsPD9'Z%aK
RwD!
:HDUw)]$"aS$
0
B>|ch6?f?}wTs=\*o0&qLKwvu#`+ n
lq%vb#'<kgk8ki1LFG'U/9\]Ge0TVSP@?;{dM!wIOU-&|td.Mxs=mH%)p\~G1Vf0e,gX-/R
0|qp{"QSQa`9?-&bjbo>7B4s~R%2oMCxuzC#[,D?.C4^,gcFWg6]i1~Gs(~~G/Zv
qA!7Uu]tz={GdSysA]*&oV1JyXTN
S\^?eQ\y.+CnEKk>!
.iDLmbHa%$:=cMcvs$=(*%iF4Eoo6&o2s&E'D`
?_-R<3
@#;MD\:._dJdtR` ^/Nk76OAPO6L~v3o("jx3'7L ?lK:sDVz2oYdpcp
\>H|#Dm$II4"rXS}{S&tc=]IpT+At'&ee,UvX(AGvh=;]o{-&DPq-J./Y#"?.H""!&%eLa,D^,TY&L~ycR,3O*H'8*H)v4[Y#y(wNi0VR0V<r
#8.k8Mo1'm-o;Fmr:Q0X=4(w%Gs"+wsUGs=v.wX\s8PB@OUg.PgEc3FZ&n}|`PO+9"p|R5YHn#hI!zHQLml%I8|ibTh]?hE"}FS&2?4q?ehOL|87mUu,a%~Z@6`VFF?/'T. o-U0w@LN7w<Gnz\nk6*s|F.fG!}M}e4i`mDl 9;VE%br'bN^`'h((P\Q(o*j$_onrb#4Yc;x{BX#%|Bzek@3q5j)8L?d86jP/E/}+YH7[h(;+['Z%-}j(SuIz
PgS&3*~.R"cqq`<`oP\7.|%o6HZ3@*(SC*FkP9YxX,jQ[edr#*_?:&VJzF8~b!
v3rxu`=sI0{G:`uL&R5ic&B\R<iGN5'=.!5AFZ=9JB`'&#S@O+(Fc)3;=0D<Yf{P$pB{Y8,I3&{#7N
\p)>g4$8XQG|iQYCD.W!`%[8x/g'BuO6R/ZGt0UgK8s;x/K"Suw^!mVnE2HCG(}|(^rbU?F-w~r'r<L:ZK'_Skt1"*dWa e[q6Q1A u@B<Zz3}Q4^XI1D[f#bvblNtB}w(sx);~t[0{{Y_9=u&vJ_EAHDn}I_SO`WL2Y0(N\6mZG$97| )J{q~:f|64Z\:uB*@ ?s1%@d
gEJ2(-4(d=&S_0xc;c(Ey"l #aPTM^?"gF6#X{"lrAH'(wAMkn~Y[(^ v5uqR$"jBY$DnMNf=IEX'xM/]{X|\PKmwt}-b|F^Ev>@CR:Z}9I)=8
s<n+-Q'0vu4/JFv,vnqmkYCPHv2?G~,t%M<Rrjo p4M~PN@3KrC"G)CNs:NiFr&JCZTV'&9WnEbO]Z*&t:^;7\?f84''?a!MH%m"2)q  /0xC$3Y2j@$BVNu\09b/-.PD?;!9wH>_/P5S[cEG4(21u`~CEs[n7
G8oWA+@X|*^Crl}Fkc^G \fV.3)TK1qhdC4CWs#pE3ra,gMbvIu<&|)3FwDPnO0j^c8!e>fQlb|d2)3<@u.$BqM/:YeV8)7C5uVQt.$P,"r{U7*Zdv%3{v*"jl_F&a_vkFThvUF+DoY@`htu[fHs Sc/]z5JCrRGo-*wj9Tz`
L?QnDqq2D/ZYhon\'iN,,Xr\VWbFY-'npLfE'v02BX3Tv9'*$dZ<4P7+-&|g]EE'0A_LQH@#vQqzr>;^pFH26t;51HH^C3X8"K$,%iZN'd7u<D|ux!3U>lVE.s:Ejnip_O\p= @/}z1;4`WLW8sH3A]\(0L\_q/+=VRWQa W/h]M`P
ZQ|^%:.fvaN9Fkq[S >k794]]DKbS1P+?JCG<3ks`S6sx;UH,[U_,qn+1~1^A{G`dSw:WeF#Eq
Ubc_z,))",R"("y UEk&IkgN#hD.S+~{'j$"HwMat;h~?%`C=.Vy^uj$4OV#*9?y6x_1j5CFZ \&PDq#-.&;K,|XCZiIVH/31_E=j#J:qb oca:7+nIMwjF(TRy0:!W@}Fd=&a>lR
~P[d|mI=&n"y K(R**zXKgq{BUqxFfM,to\oBq;9C!;R;;_`"[/lC(kj:E~!_Ns+kpj[L!h9LI3w?]e.//Pab2I
RalA*X)
aCGmHHq-3B`'pf]b
n&&escD7\KT*@UOmlru#Ego7Kx'O`Q|;h|x=0IR:6.b/)#CF'QJg;5A[&RE8VBur,eB2:~4E'+,4|mp;Bm}M7D2F5fyAvG\][42VsUB?kt"1J9bOamXJ"!WhwYScGDC;!](s>N9 &^9zm9l8xzoE,DB('StOstc\t`@dR,}V4m*p(EpwvX.Ol0UyLHk<s&c&5vEW#!!f0&;D$g]x$~5^%|F'INAp*;6+Brt$u3)(j>Bd>>Es*c"V\6CH=b;H&hi:0Dl2b+%3ZjJ+p_)-^W=?Ls]TAJ,JkUNcD#57}4#DRRd:A_O
UW-m&]-cbJ4sh?M|]@O3$o:0uL4eB+mf!|2)YPc'I>cWig.,:2[rl|=zZ:%nVC}Z4>svk6rU-_?KmG~z4e],M>gM|6K@5
TPwYl[ vc|&2|e!cL Q#16J`k7lX9=nH+X]B8\:K
e>C<f1I*uqG4f[5P82Ziy0lE5|88C'.Kv[TQ:;.g?Th@W&KRGO~OLa7!TP3s[rFNHbv)jwbuI<8#sd$)@c%;gWVI\TqV_.U'Q?(pNxRrNaxh>"!X@uW_,yp-[/$
LtvP"er(--uV3F
oL?g9G`1l0]xLQAY"! C@X[jE;NfbTZ@SRP
Z@h, 4``[Z ]W~03=f?F?<bM``?(u%B3UqQ\CMSYfDt5^w^Chwd3O^W~Zj0roM3,>!L+VpOO!qwMgCY->wTW-I)$UnoT~64?<.Y#NIp}1tR41mv_j42n+\ld{S'DRs/)v$^p*{VF2"$]`v95'>D&#=E}4q+AlHWzY?3Wi`"&$|Umcd*ut<@snN(X
@ubmE,f]}))85dC97Ks_$RLh6* ?Rnst]qAUZfkm]qV_G&p<VHk-'^QgX11B8{=_O5_p JCi!u]2L
*Te=el_zxT!ziILL$s}#0Roi%)9qO2%MXn'/=&<L!Yh+;9H__[D:Iq&/BG[3%12FF~!S&MNF.Z^c#.N8y%]1/X[i6BgJk^&KVL+2%9yv8H&B7vF@trS+i4/+~ctu1<M|=C"]5<yu9~S_g}R{-4g"R^9T[!mXqibdxnL(OgU`i\S*
s=kPte $_'mz`=iez'{
Zi79fu#1^mi})LS%<<
K6cW[0uo}:6u@SO7z"4.|=l':*SYmec3aow*|QP-NF=~ ,sFCQLp@8ym8JFMlQBI_Y*A?`pde'M
-G*nPhn4l7*`p[>X/^g
Y\h`NDxF}I(B/IV;Py-`rgo*7?N}v7*zZ df<?EV%{.9X|88j5< Lt
@=}TlYy:NO'Acg
>pr>p9P#]wX+8:X~9{0Cv}.9YruV4;EVEAfQlRBXq|5iZ'_\sQ%_5D&a"~=V5cNyOvKU"tU@_1EL9H,i!0#k.KgnUN~Um/EZN<RJh<N`Lt}z7JX&,){Xn9 J3%lN9Edo2UvBQzOP*Qhm/AX2q$
/C@-Q$O`WU*f5T:_X
c|&31w"L*`4kSaHz4H%vfSF_J$;j<g+?=(jW?< zZO-{$Z9%=WeMT\qLO$My9?nVd(`aIb%.S~,V?LidGM5gj$y5GsUwB_FX?J!_&)'8&0o^bDd$jSMAeu7@Ktgq]'R=CPG3>Ee0bTnBm{&,B=Q|9I*/9+6>8_`
mj>enw\SM;v4i\/dFAX[da!|G7nI)IAs3Sq[<sCOa`mWu'is4;F0O}gaR!mH-xd/FaLad{Ic#\#mg 9nbL|x/HrFL,`41$G]MH
r|:n[DD@)
l_Txh?.E,N#/]]1!C8"/d4)2XYKC]{Hh2*0NYv$:LKDa8 ._mG*qQBK`zsi`oO~E{3Ocma+3oP`Gy3
9 ()%Y[2yq&tAtQyM@vG]V}I5/WU~7_rmIp}5{UA}qo?-1!3>x@A.^*/mWpGhuA{dh9p_D;J9>0_~<hT4'BL7'x}R|S=.mb,=<+jdyHp<N0Ta;j[tQ'<[gSR3%~eBtQ&$[*91_=7\^{%-yxRS*fUUykdS/]^pq`<l{S%+49A#~jm>s9G{L/Hf,*OsTHH+#sgQ{tB3.*#%f1oV.OWGy/Q%x[)&[\%y4IU
'/m"HbV(bp`BTA!jfR_mf]O)Y5q  yaDPq=dhy8|
FbULCsSNs]tC<0sG8~:AwOJ%;Z5&9Uy4i lX41*GASN`geZSDG[??LGW9(r?!Jv1\QAg"3s12ho`&{jg>D[5hPdg+,awmkp44jp=q"-G(H3($:L4He)6KnHOq7g5+E^[f4c_(u+g?"HM|/R;gYt];`LT8+}y+KVi=
(QMx"Z_sluoX],mD_gI"97w4"!XWX+U 794=Llr !C?m/aQ9_a+|kA4(-F|g2HU3xF 6\.Z7!F0mpph14 !Ll<`?bVQ:#n|W`"6%l/Byp>HO8e2#mb/.K?\\=P^-v?\&/rp-4|MxVS !TruAxA9GGkCi~2f|XUH
[uIlUZH3gd/
[}{#(:-'v(6sgFPdfgjBp&+#G83#qy^PRSs,$yLrLAd&\C0]Tq$4>I@|K~d($YO+ANyi6u?
6P{Mj"H&lIvz#?~mZ..HpG'PL0?Kw\F:_L[Yn[,ABGXgV(f2Ya7(e?%dn:7+oD~K_n$^<}pDxficM!((\%ex'UAd7V(wy~<nhe7S/6_5k`d4cM{<mDQk}P2ab3wek5m\XR4?h'g'E%88'_*{i?kt+NiYcpZ8{y3H?/h09T
oYa *>LvrO76%9Xmg6z*/r&D#I:Vv}i?(+zf\vB3i?:;Q|+<19Ry`n@z~` F\cSe.>AD.@s7a]S&LmH0`&x:KoYq*E0C"eeP_ydzU!5/
AbV}C>v5-o%,n48%'F>J>3~<yG ! \OaXD(@')7h>)<K@D?"*cMx\uiq-.}LbW,vvv\>C!kTG~02-$^+s/;M,O$I8
.RoY0\~mt|rz6P+p/J/:VED@%hHd_OnT_%dY|6M$6;!!E!IE"D*8|'V{{M%VutjISClVwwl^f7h&L`fB5?3W^=<qvmKZ;Lrhn4jO}*}--qQ8ei_pOe0IxM&Ig&X
f$>\s3=o!<cDeB
j.${y].4s?pPn{2x3>F"hedF5i[:8#hNpSo]VE9Fa4[2i;$!&EK*
E&j&SM<Zq|elGe0m4/&%2^P#rj;,Dn<79r#.3%**J$C!}}=5Dj:##fk2piUt]!QnZNTHEa`Qpi6o=v_BHoS9Fa-v7
Qq8OGs]KVdot0(J{OMt'yA4
<'yx6W[C]0'me5UKn$T(X|Ra|:.qG&A<APeJhsVOx?>/18h"Yw*=UwXdQVATS5dJJ" tPeSumf9WL}_@;~f<n]#QIbmyX*E6Im%0JQ*:=|184gUnSRX&dT*g]`yBy02}gmX*lJ'eyJ)b
e oEjD%y4h)Muw'&pGJ>sKqn<Fs\>M]=2x}RsC>t<`eMzo&3]xC?<,YI"Ia^wt|2VV_ddV}Rz1&FMW(`1-h:GUX4p$;U^5B1HA {%"6X2gU^`l%X8oMx7.*Op3mf&VNHD#D5..]*_dr8h%6&]Vj#F<3A$r>ltx`pDSSRb V TV7{a.qn+7wFn J2+FxsL_>,@!Kkl`K !]Hji1IWFh4(^)*mP*)BI\t4-L{&\=n>4 9=|KU7}ym XR4vF\0YB7a\#nsY. L[x0q<+y=~oUqRtTcWse'ymi|m\&-U0Q#^{;j`heBr$b[*{:.]/9>-]#nlSk8Ow?~~Tlk,|<S6wNGjTSW"FeGpa[**#bbrf)cO="K`%UHgTn2 4>}F~TCwOFP2oW2/|jQ3I\a;C#7zZa6?tF$:$:LXvMg3KENvtF0Ozc[E8357pd,pgX0d;l$vq[Y2k9]'
!V5_dS0_xr0hH&aQ\= #/9/S`=kx(96Hh>B6LT 6yqL,&o>ZDH}O!fW|I<056wAUnFe%mqy
d-1$na]7a{XQDyU"y UvNSV+H)yg'$,~'c(EY0d2Ui:S[JvZm`ow<j;&Y0+QFRx;Qsxdu 5a^8^U:}Qb3n,5@\q@M,>Ek#v0BAuQIn/l%%0d|sw?l@edC7=v(1t6=)(u8tSUkZJ!Kc&Ghy}(Z%<I=u?DUPH`mm9m:o
XzuN\Tw@:>[nx:m-3tMENArK^fd;]:;4gn&FYEcNW?%X$2&\4r'DMY<w6<e}y,}'E+\`\8"<u8ekd:14v|)KRc"/(]L#q\"o"|sdeq#6mH4fiA=tN?*$qk8~g54/s(xh)^*
#E[&z12`q'a8n]O@*{"Kw\wxh/zj$tw!G"KcosN%hDj?m>2'AN;#qyry<ep/ gSR`85(6sfOn_^Z~rD`Yn7/oWq2?!~pe 6aO~49~vj3PjY{ZZP
LL:BS`m)%S(DU|m8Be*4U5M"T+2BQCy(Lq#Y,~;;{ooDiw"`VFzVI2%Bu~-[16@0Dg}.Ass?Q=juI4\3B"v'Ph<wK2=vbW$&bw.U1yPZzw?_jcqFz :u/p&LW(FGy7?&Q"mfC5C`=_bX!8P,\D5repC z;P;#,5mGhhUZKN>]fE'$C(kph(M_<$Y) _@uZVeSKu72v]l<i4f:3Sv^YiwinBS6~ixciMy"TD{L0LAK%njELewZ\Mb_LPa>/%8p C0v/1rL.-KTT{gV%]]K@ @jxL&
$wqWS2Mre?|TWHR-J\%s8t2(,1FsB0Z5Sa|2f=eqV\llenG$LaZ\y;k!30NyliTf{99*@'1<xnT} <8,r(iHFnneS_[
'gr&N:TT?S_{+@X~2ZbDYPQru[@9c_0{)F?$ruEZ5`J_}N8i;)eUN!W[hBricTlHCj)S.q>unANd;n`S]"!XWXKPay[fgH|xRKaAPsDb\M$8vO}m~E PO-$oP$4@~AC/hf6Dy&ud.eFXO>2Mx*^NoX.\\yd5.TI@-Ow^"p_J4Qw/9 NxN xzG;=s, I$0,Ob!Rekl(DfU|~f17v(cXbo,VOJEHF]/T.}Yi524i:bv.;p5)!MbPt<fqWw
mX9ul(d X3x{/f,&`p%{FRKVHlk\6RY:0GOEC9Oyaf&tXD
Jq.'$3to$zi9y8-d#_I~?<O*{:m22hk`<;Umr1By]5;/hjf8_d~CKK 7 Lz;pp34%0_Oq*l S|SU {eH="DQ{an5C:Q-ETFZ{;Tb'+}Nx(;v\5sO}A;.Mpr?Z,!?O7:%>-4:}WQ!$&u\RAYpCo6d2
>/%v9D\(JtrZJX*.*U?7;a|)4~~'#bP:Dp%-0<LbsSM?/ $mK^,{IXs#Y(=5'w <\|K=N(g>/6\#7vTiMUVf]<,
\l/0]?<yv/8mkYUKuOTei_<R$"!?PF_+5%pHl794Y*X@ZNxf}(hu-Ir?mLfbe6?QhCzs5nD25WLI'sY=?itb.%$`u{N;:e=hlQ(DC^%6gR,t}KR
"roL 64"sw
p`)a1ljdDb<Vn_b[l%:h^ {8/WAc;FkJ;-Se)Yx@s#vk_&m$h5%P&CbQ8*0
i5'[-xq`sK|K190*|1,4!O]l8(RQ?MeABBiq$\)sVB=>vk<u MpCo5j#7!Y{5g6h{fQ6RZWPA1*b`
WF;eF%z2sg,DB=>@sFDC;Z!V?!.QSt<s3cPlONCM`K5y<<|"tx#9xC~2ZmWf7sUTn)e0]jN):bi@'!<FFE%=S
|}zJD#4hTaT<.\"I<fT0{Hqi`|Q5B\J?"=3Q~h<Yq;p+5+xou{IH>Zyw6 !Iei_p"\_!@c@IwQV?#1#{u~%?lWQ#ed6gSPv}aWRqtmZEJJ,a%Jc]9S>lKf.I_-]`w<J:>n_0nTAIys.QD]tc]T.DL6``@&SK,gW>&-lGAis6Ss7
NrKnWy&"sK.r'e3VxO?OI=+@Xu/eX]'6Qh
;+<O15/.rK{SM8d{I"~&kQ{W@Ey/?l_-e)6Ni*OH/bs"7sC;4JV
E0`wvVS3N&E'sr_ 5E%A5D@E/PejxgcSUWoU CnB
X!$T82\<aw[3?:Hx'00\fp;eL]Oi8kB3IZa"~ oqV\ka1uhZ<ryf+1N*@+(hZw.NU4KcmwkkpJ`K#>nfxQH!j&JtF_QUy~GduM>{ESI`;+o3e3R,k_6yd@Y9%o!Vmd>?AM^{|,]3w;AKNyHo}C4<MI.Jp*^5B<|9.@%l/J {x;;4
rF;nl*pQ"<ghf8jl`T"lfkyY3;p)FTgWH?a;gwSYd(7#eQY1q`]bF\G6R(#/ j&&I}\4?'S[F'[<0WPTk_6ytRc=A^Su
oJ3#T:q"~+?J+JqF+B5\>apzRGJn#-P`23C~I'X@4vUr/?88PQ68a@+x[i^<l`e1S'8PAkG|
h,!zp>tF*}!|BInL5;U37rb"??_]0L6pF+U$U}G?`c$"Dsc0X<t,4/'yn$B /J^k$Z[eeVx1+y!p<Zyv@?=z]{pfA)2V`n$AgEi2G,U;
Fs&?M(&NzC^^pNn:ccvSpx*h/7'Gm9y88LM6+@X]B]S3>fyv.9#l6k#6L5e,KMy'Zh8Y.,kzs@X%+5V.U9o;Sk{uUA[$Z^<kN-r\4nx6hH{dPr\\N}oY*>>~_lWNfOq6@s:EPd. LocM(&hzN2H=\U\adqK}[_ek4
U7q,"b,lwM q!Sy^|0qcP-D0p#yjH(8q)ATEw\oDi^)Qq\2P(I(xy~ 4
4|nr[VhP1t+
{wwb$h?|OciL')|ZH
W(:0gKsgv8bJ0_Z-Sym6"RO}opU`Wf!!ZM"/kaG~]uQK0)X?LsZH,AaO9XA5kZ*~Hwdcm
P
ZM`j.:C^H+hoz%1)@q g7MCtN}TuQ(1))",R"("a]K:KTz\'S%PKGC!DNfLtqovi7&'on.$#TsOY"%4`4x&LYz{edZH8[;]{Sj$tm72y(4E'^w>OJr_?<6fK'gTs7b^Hpxk7^
QI,DB`v`UpD\tLeYU3"Su}Gl_/J|M.@U;u'5ekD,S>n/)2.,,+(YiV@x?EZ?wb|ME4lE,%9V#ih^x GP7asGEgWW>*+.g|(]<,^m<2ekLGEvG|@hHEJ@"R2dH
wI`dKlSM8c?7uj&$rXX^'*-h3D
uq'3W8^6@3fXHVqR(&G#{,}O~F^HZW;A,iFMBd?X*=e>d'`R1;<l3Xh:^;nJn0lR% cG"{T~:><tnVxOuU~u|7`Z>_!G
=2H_Yh>?HPfUYq5U*%?yap6-`5\|hMYMq%Y6B(ObyH;RtO\.vs1|nWu|+yJrUtx2/O>6)lZ1+IUt$co%ymI\AJ&8U6SY-\{8o]eDPBk~%e,0$B j.:n3\?|*4oeD~@IgST_5<*:GF`x*r?HM)D4l+Y#KaRTS>CK+C/{OW5qCdswC]W1uu9&
o3B t}jXaS5?47R)BF/"Qow!4;p?';"Pwc%bJ\|z^SWFg}x2_Bi `)+I?W7ziVWt'&A Q|UE{la44
&#RE\$Tuj}vW"[@%XU;Y8#ED:Id*wP;T]|Rp^xS|>ufAw}Ppj(')X0qtuk#[7g[_'X*QE](pY t</;!Q dDCDw%z3EGE%t<9?VaOLN/qlG+A6p$.tOyVufk3MlZ]S43HTS=}jj&T
xup^vm]DQsjF@
h,!{VHF++Z7)IFXBk=~=[)`i[k221
pKBQVNj7,v\zA^pRrNoiZ]-z{@-Z,Hb}Wx"P{Ya~{BUVb;+3q5CeG"X Q4yC!/(SZX%
\Q<?vrs~uG17&Av8kUO<'~&*iH=3Y!79|V69Q[#1WJErM:|JTf|
,lSYIWnl\s].Ie[N;MjrFElq+84 /RU$_%'e-z\ &6v$i4$2vcEzC|cO6/_N#Xn$| 0!9[!-60o1M6-NcMPB81r'g6:8o>MIKMy:Ibf@v?3Aqw4;VZ#\wc|hEgf@m/Dkvtc_'>=O|R k5qEZr5;ZgZ2,
L}NU X+m9r#AU#:U?|VVde # 5VY5$;`U3*p+',Hz)yb37'^tx
ib[d|66 PP;9o$[EDmpL7C&MBLW5u%&M.-5 fB8yh[hl9wgO%8e\$"\x?VG-)N1O3V(Pm%0rs.&sk8f*0)/ww2H*8Q$
$}3SX"yR[cm+0lV}s<Ib!F=SjHkq]hZv!jDlN-nqK%K&)hY/]r!U.nW#K\qOD9vuOtN;NX-Q8q9*mPP`PzQ \(`C7RTCnABH{VBJ 8NV:TXD}8q<b/wY0NxfOG Re2Cr*F]*QyIhfD"~NUy!7)buK^kv][UYl6 2KN~xDo]? qB-0$VA\fLwRN- j+n[~v{&;o(gbs9^D)l>M-L%iiC>$a.# #
e1mK5q]E
[$iQ3+kIW(K?1No7<a9Ai*|x05{v8wD7[kU+X,,E'pWmB06ieFWS}Ht5no&KgW7blu65k3~Qw$Z`~nwNa%c"sw%yF00 ~R;~&q pwSe1XR5'9(LEK*gxf kP-vJgbxyFM[$mh0g`]sfc7l3
?l15#=#A\gQ!7k
643qc}wY=8{hX,H4:a9D3)]}SM_4d0Fq'r^K\3sA|roZ+EClqZyE9-:)="L3)Sd-s<D'nJG4.H<rEYI%*`1+z hS^G/"sw<ez`)k2_E6'C"[1F2rZ]'F"*
U6`/wLfvxW $l~ubD#D5>f6NB]6!k^A6&8IW)Lm#~v%TD*mKenNE\K34 !89KIX)n`PtUkf*>TcL3bd<p`:?7ZX=,aCjArCa$CfP29K&,Q'Klzw8oXUE!=BAYt5k:H}4/6T|=D6lt:Zbk;qr|Y\QON+
pUy.slGQxOmJ9Q!7$O+qb}m>\r[LX`]tVOpr F43yBPZ~dQnrYK%KXV[X?Ej|oSWLmlu@?,jX45ZXb`K.oj(cMy'[)QV9/6ZIE-c7yeoaWVS"A "&" "YHE.##cSM8cad('<"wH&#7bjbfx2rQt_<Di$L`)i%B*vOZ!PKpKcy/,
)h-@EafzDExrTn>
k3$co%ymIt6d7/:FAJ` (;o2Z#X@0:p~H4"7x[Px7
qVT9Xp-|s<?E[4Ivx$O0aKXg2OZfwzlhEo1eC4i},16LGL@PLpKv-2TtDd_[)UWx[`CfU5p+*F0dwDV:(kQrsoK}[F.^<s%%6!b6Q`(${9/yMiyI4EBUa^(>FJIV7TET3W'#"#SM@P%~b.+A9RlDR::wf=+2\+p bIabx#we|?`K/VA3Ran:`;:
+5?1 a)).fP~g&vnvk&5OL9('wS):p^0c|D$FpU>A-UYl`e-utCrNE'a*L{+_/A_Xr4BX[^u\@nZ7iZ6(!:
W[ag:qtmS3W![Uvlq;$$'3p&9%.z0S,132'X@'y&OL,jFDG=VXKI~o]tB5s#/MHn00sMswEK6^a%GV&whi8LkfZ]kV-\johurO\#`>VR;wvc`5GQS2/5xnCzd1RdXP=Np"[]Rxo-Ev#Kp
dm\%V<i?,~X:`VyiQIm+.IEc[bT08${ZPQjZZ
)Ny%'N$k/<B6HRBh"q7W^^C4CkXVF.z/w
<a|h`Eb9]&r7KW35RaHu)%T0&O{:!+3P+)u0~`/xS??nF5f^I&e(R!aG}15B@}jg,x5OpjiX'>qpa\i?qN}\q(yxZaAm`>!&d

|W]#)+4C=FRh*"q='#v+Z[Chuoy!Bz:Ofw2Z{CjP5EMDM6$^]!Px6Bn]y/1Av+qz>\IM|49x%i~IdEWW#SL%""=C]u|)2n,G1`;7/"55F:c?reoW]G9*Rce"4&>4qFy'C&|V9h?,C2FF/3P4GJ6@\-,5{MSn~:j3\pE`^fip+U4t>v92J^EcJ%`ZJH_+,$x,uk5^#![bnmUKhU7'Hzr9nTg6WaAz,<qNwKq_/N1'A_hq5, 4$,=F=on[=e"b8g"yS)v#g}4$s>tM^'EXD?O3;zR*@o(zmmTR
QHUbV2T4XckAiiA9RW(Nvs$G`T*(
3%Y<
\qV]R}uIYPc}v<z
EY@rR*H1mKs1T3q2gShVJaRKcC`;Uet;rz_00hRxO19,|?3Qi)'IN^?Q!FE6^f5_,g5r(s&NRK@t[8#'_FHXy{6yIBlM1?>`q9s("P\"-_f&F*LG+I#o8:rsT)F8#+&]-Fq}J
|R.sP:]Kbz[DVd:ljj1/Vc"+RhGu'GW9(]db]>AER7S*7Z'/f%)9;VkGtVm Ghe9fxxO~]A \5Q4Rf#|vxV]YdV^q39^*?8kRpn6~6_wp3S)?lN-%[J*ekb'fLs`)d{^zZ'yH=cnP:<b[cE~.=>&gF*F9
8)1D5{:$Zn~UVgq/pP<cCA9B+_)}XN=2Y,M,
5\4a;[lKBFDJ(4gezSLFn=^YvL^lRRm70L&::\
]u^z/ R4~u36!"hGQ?3a^@&8zcQ@b9C#+|K-|WQp_hfZ_nx#5NW4A
AYM:
<VE_b<x[
U-ZKH=R0a_n<|53<u;fa7IKSbRLMA@h!/pPn[#>mL)6N;%%@/Q*Sg6q>SGbV=_#Mu";Ev."@jQLd3`6F,~Op2K`su}E!:Z-Y6
5x2wET|BN_< [v)ib/J}Vo0edVw$Gl`)&h47mPfQlaF|BIRd7%`<`hbaDo\Ye-))",R"("mFBPbHIyLs$O=$M}:uRZ4k^bT_h"m`u
XHEC`ZQj^42Qpn?2"QA`K+,w7&>\]}(m<\}%nq]S8?Ek^2We`0H<;vX0wvHkkw-> 9hH[pT("2=XQG1!qDw6yA+OZKUv\Jzhq&LH1f=pRAepdYgSOz@V_fIP-j`r!d.X;l|Y[iNt/p[*+!@Qb,+)ysl[E19!fLtqv}t}(F&y3JDQePpK|dZ[3=QH&9A(jcMuw*L^w.]XZ'&&mYE lq!W'"K;|G[F=tH<3whM6q46NKsp$DDYmuT|_qp9}H;BzyM*NAq(4E/Zl`EH]fvZAxz_w$[D)Sa6hsO}T1i0n Wi"j@PFfS_.@~jO-{?.[B)~_d<%
6x&KaQ82ogSya'ou-p
pFO*T4rN\3fu~F2y?&?FktD^-^-^!X)b(t.BZMkou[T6wOstJ`-~~G-+b!)4u0e5!EU7e
h,I//TKY(
{Co4$nX<SJ.!
@T''&Eoq)cM|b:q$,Q*XcO-{0=P@Q]XI_+l&!gjNq=i>.j9pJ@4aw
\y*>&$ox16c
n7<VB{`\XQFEukIc^Sa0b-fXLx]?3#;{,U:@e_~I#OE)$;@(~l+Gw>-V'HQ/_VT#Sp`[q4c!OzIB7# M+@+n\zey?Xpk>4\UvTxf&vA;W{"uT{<2AHUcw2})=#F%GC~ChS!j3bt!$S b^2!SM@P.S3GpJE#!V`4z[[sX-bhC$7DP1)n9[7;r.0m^\_(a<0YlRi:`xXjo_}J9[{JW@.YI1F4 cW&<mn6LFfW2o^Mq@kYJ0!`bupOU9e$9E4H=O*VKVg|[\Rjib:3Q+E9UL&-Es"P81U^plF$c:3)m+b]&`"Y-ml]>D@0b+ohg{D0078%uGIw.q14q9=65qBUusLk?|Sc5K>PYi4z:*c>>rs|tvX(Kh"N_[#.YEdh\Z>|bNS_qW?:>\k+U3-fL<2"hHFcLHR]Y(x*@^?Mx Le]?n7_}|Ejm _`43Lz?=og|b-,N2"S
P?B$W(=!@u$@/2sA4PF`r8qHaO)gCiRQ2Kg? M{@nk(X`0
+4>|;,9WN{(6T_
F+,>;=GC"RX,c#= /H*-S"%Xi!4lCPlDHP5SqgW8#.m1O(4EEcDSGz5"j|A-Wx~nul9xd"^u`jZ3EB#d7(~LK4!]?Xov*\Fg$7CC?#+g{ZAjT;=2o;Lp!UjZTZ+ArdVa./_]Rf=*yZ2JGDCfV^me>'ll e*?fjpKc?n $NN
gMjpJ[-RfhgZQKgHsDcqS.$z.JV}1_ET.#C&u
;!<}$)W:~sn\MNcY.{a}0hF-n2A>EyuW#mus%i_o"f*f3c75_a15$<TiZNz<EK:r+(`*9@<v=Nm7=,3NZ{[:OLp(=A8gP^kn1DotcTeCGQ
{GiLwUsm#679P9iiE4QGg:5k7YkO ,tNZdB5iCH/%f8dz[w>G2feW!R`1"%DM12H7+1=lL6w!(Mikwuf*B!@otI-j)IeRa{E2VoAC$0Ap+Ruvth@|;g/R[,/.]U+rmD[u3w.L4ghr{B~pI-<xG??[5]P$H9,uao<|Z !f,t<kd+HsY!NC6IlTi2<:{\2uZDP3)$vJlXRkX
HdDbMfz.X@/I
VcB$df
\HZFMg'F%dQ[ AEU[h$Pt5CL} G9RahR(htd)9_OlYuk46JT%.[3GZ0hEn(HNw'yKm{-T~=awK5nbj`.{n*MVkfK`Lv%0qs){B7%>{6Yr0f,*72*>6rSM;v2uaQM`rrcKh!K&$bISQwZlu#jU3.>Wily'cg~wf.Cysp XE}c%6p}A?V7Lq`~C :_d{l%
L9Z?>8/H/EIrUky_cX^,P
Fw+tV0Es;4W.\^
.\n<B@Y 9v-pL4h+qh
\vuCSqsPb*fD5&tD*|
) sD@Dp+aae{{f46JmCt{QDzOPLug2`GcXF8^ss|QMDFZ9JI[g]#\MLFa_zC"E|.YqOR#zLV>08ActDm|%a!LvGOhYd<Svl#_.!j9BDGEi0kRj2*SrK+7.@2cvDGZJ%oX$-+3S"r#VUZB+*Mzd0/dTuA$~/HC@%5S;S?l1{s[I?sI^+NW>2b\g3N<Hq^2;0nv<dg7.NN^Ynh9T/_0
J3=R
n
2`;`
;tu5qE#qySfHH8C65kiT.&4{rU/Txbm1r7'KtC_{yeAX=}~a$2[&Mth"y K%6}kv;MQ5)DEkGz)eXOJ (XWe< )|5kI25sBS\sBKHM<|x(e7J;(G|tTZmvKJXb?OT$,A6B0Q?}_zT@3U=B^Z/VwCj5R~bs.gSPi?W]A .V?GG#d  {.b\k/>d[<z$w"%LGmhL<Q0$R$c"GdtTcWPAc'BtSL$S7Nur9{RppHm(46pEQkuyW$hSQes`ch"UcRn
CG}>H]L-
f3);+2R/3G?JWEQL<+U$U}D
v?6DDu{5+b-mj%}7[.Y9#&H7z;^zNOLc4W}? T|i<>Su|v0d-}d<:_QZZS
;&rAQRhky/6SEsrx/v~`j}<E])5@Fm.psC\L*E b("?MlO.
UO?^W,S+EM3&xvoo{-<,z(uzA{=L]<^r wC&*$:}5m+vPjucEyt#QsBKtI,m?^^Q|IIdLem4];|C%ZY2W`P]Yd~>0SxZ!n6i7<j
Wn2|s)E(VN{nG^D:c.*#GYf35G\o>M^-ajnarrOidWiQ*n2a^>{(2o!>&iuBSiDgxOaT)Q+1m7n'/)M;tx._-HRbJ:mkW Q!1Z4N%^kg't?3JRkHs+j^ApiZ|XrcvKqm:1IT9 ?H@p&k<w_.Rz!\1?hec?p`\g"CeaO,NQ~cDH==!s`9`LxJFJLKWJNc_.x;(6/=`$=LupW$M^L+hV T#\V.-?hYf W<:jwlFR
B~C- !f*>9#qGzs{CGc2Wig.,M&WZ[6*]ZF7l.xjiJ;
u,0T\3Xj|+S7nG~C`c'%ly4F7J:b>1j6XrJ%794JILlTtD>2!|I?Qa W~M<~/[F7e Hwb
%N78g`279||WdT$&$op"S,
)/CzG"&Ga!0/I#kz+ Ya~{
p
-l*xdR!6S#\TxoUAFv7ERF>4,Gd5I2=I(J
V#HGM 0z,6-?&(3Ebwl6q_V*^k8bgA-s-X4~'V)\a8-4~u01uPEw^PrF\@RSJ%UuyTzliSvE,,XF*-::yF\6|\|x%PZNpxT!z%1N2QFX7YL$[!FRAu'K]n.b <Xi-8W_?b}MU:GE'v/s5fgXg.x:fr!SD4dK/DU\s&0jg5PdQaS@J.U*^vc(&>c'3MlC4j
e*gOyC:Lp[%]FE?j"$D@3yL_ V8/21BaMwbW1WH@e`o@4#CCKn;7wqB)r.93,f L-++O"eP{gGQQC:<AYtmr0sMTDm=LW2uRw[=w1a|(V=5#` K^bZNyyf
Zk5>6FGn]d{z_x_yNOp!^nOp48r?*D8Q\y:Y8.{+&SN_ru@Dafc@0/pO?4Z~W&Y
[O!\AVRs0fZ`SdG;]eNEQ FmUO3+Wgt6.-WIAB+O~Az_l\s('9f>kj]+#_1;"a92i.2;Qr<xORZW)kd=[HZ^0ZhI4)S[d_VEN?T;1;|:Fo;_u*v$Y>]mH^Oee*
^l
5z.JVbkf}R'-<;Jg!
ZF(f?jIXZo;"BO^imP`m;Ed^T("vZEFQGlh'nGb
%6pc_U5;l~+Z9\/18L q%@+?/OR.j~UCCJW3$:}Qz(Qtap.R@nRkE3;]L'$F$.[#'v}V`QlUdq`hDWG'KmGXM2t~4X5eTGw?7Fs`i[aD;:cYWaal6/^x`d^Y/EUoca^*fJ.=+a[0r:jY?
nK<Hrp"#(!4+SSHDOz-kYl5.c0"HngDr'@MSh0Pxu,Af@0o6y~tf3a(>?{>S+.BhudG|(m,c#^zhynk}uu:6X`u_`eTv0c?F9"F\yn X/DI[TldL5&6ei`;e ~Yip1j.Ee@vW1qN|:%&Mvt
EKbp$$DIuQ6}~[8;6B:-+BB/
`hyXx|f=+VFj~pCL5CN^TG7A&0+}^(pUN\w636QND)v7m%JL"nDv9&wP&P+K_(VXvpD+!*B'H4J[D:J%pv7ACHG%e5>=m]-n7-Rtg%|jU5e-w8xd'0[DDE <oDAh{``xk|"y =U!3No\IVmj-k<^J,W-y1hnk#iWh4Xf`6GGu~3rnhm.+15\7^BnGfyKTelXsFgyZ[m*waqk(hg"VgH,9XKk*(bL!O]ku&9QTxraaGW#@!ZC5
l_uYa:JZ1w9QAQLZ)>p"qa5Tw x} as%.}8^~GNIb}Dp@`czFOpXR~7.G2p<%|SGT8fbctDt3'po%:k&Ls2BswD\$7|'ETtj9,;U&g8E@">L 8E5 B^;u^|A}H8M'B$3;!<6X2; xjV)((HZ
20k`^Yz2Q,v/mA@A[BN7 JRZ-jK>/QfU?Uj`cS@gY68WKRS_I3>!R:*Y\&[|AwDfd&SqB%[IsO"|9"V<E
ZM,ay?@^ uFNISLK54.MFa#z3Fg!7Oj}Hvw*JUCjE`om]_<B(7]z)6QPd>rQn1A1#"E>feF!F*.{k,|9Dx+).wlxCXVZD;\5!7gE6,yHf=FY6#
R{5+RTt2,+nj\z3a\19fc<s&u#Z[TXp0]oUcTM=aIFQYu0
x5Z"`}L]J{\|'$iNVT;[J]]TDIVQn+Z"!wQ-!deE%lp
F"R%J4<:&iv2:rrkZGbB|O0UPW$+amc
h_)P*lr4P!R.u(m:G+Y,x$"Ye/;!&rLX%]kb-lv/:@#P$M;`jTU<lK&QvA0J'4_3cuK!t]9&;?G,B
UfnRW'a'`D4m/kB^`p._Swh&c
>8+`d7-#ie)u-njybrfyADJ(_v~`_{4|OptM'nN71WeMg"OrASfLuhEcZJ/Q!2zVPj_z3~TMtS%aL
ED-<(Y;'~*_h91s
mhJ;[;'#(^eWFB%hf<OK&-j1v0YhX!7otV%DQ^E|V~f Y`vwo,yKlG _JFB\]U9G,,B;SUY~A~Z5s
RNk[-41X)STGsP'g1
z0$G5+Gafb9*z9 =Z/
"`$t,f78Zg0PVm|('QktV0,oXV;geAdb^-Dqh}4
)zgTB?s2uma
!o/FC=,sy'AN;prODroL_](;9~89wq:.X|3^W$x9%5P3WULlY'5U7c2$5<OQ,*%jEm74As,Z}BVAzKjnCPQb0We\6aQnty<76q)Yluq#DU:m%gxL.Lgn+cEObg^@5&wn;p0rN4f_\X`0$7IGn_8["{#mjFAmZ7*DO5*&tGi924Yukdz/x.n8T=,:l`L|:,.u-uRFA!0!9Ho!GTF>A^U_LwLD^cD(3Z*7iG(3&*ngH8?Gh]?Rs^_qi%K0<sS7ll
^Dk)/J?t0te<yAlc8>1kd)5*'maNZ$Sg l:%i<B@J}VjX{y2or|")z:]S Uu>[xe4G;,x;}?B"$SB't8 86/}N??W\rU'P
XJ
!DmPC_@Ohv#q~Z%Pf}!RX2*9O("$HfN
V&Y.Sy>J1F1edT9UfFk:MA:t]pNYgMi/D?m6J(A~K#585gu)GHoxXF!i7f}0S%RDQj_!<CEfRqbL@.]X]:JEOKynNzMN<x8"]Ll_D73?VhmL04'NZj,!Rkg)/J1Q/uYKs[Z[<h).:~d5#<W#iEcPA/8ianP
ZMcB\L;^qj3Eb"5{j&B&n;Kq[/)0o*}@t(&5EO7$p`.hg$;Y#^[VD%D HE<}z*zJ&+/c*p(OY-twD#IJ!PY?+>Q;(Yjp`$:L0-6D~!y4N&5_^n`'!/)~g>o(}e:Xg/_9!W%nHwV))&#JGJ/{#SMASJ/!#lw0`&:9+dqe;x
CC3dOa9x+/1WQ $$LI3F"IkWJa!g_e2b,sG5'/\txPye"]gcHIR'%C2ZGX[nw3{_<Q9#X|i##DrY%"0&XgF,|#i8Yx5J"rBd_r80c>Y+L0c&knB$#c9 4q9otzP$T2G<3<6YHnV&</%dOHHiR[".v1{ZD?Ezb7}OU0*G#(bees\P]pQ`lC6izCA3BK%Z{ou5YL/9rK(W1jLlpm_R[YVOSsB{8PD*OOcNGI_[q"@Q~B3p(YwXW@]* C_|mi|1CP,s?2][s]2ffoIWhI"=5`
PGw&^1"koqZ9h\r+_C|LE)$QiHY9 A)AS
i^KM5#;J3@0<4>cpq=7xf:9?{g'(KIRhzT{p*ICI*{"gitxFN@GY#R8"w&ZG*WAO=AVZn<:W[BfC|qjb3]''_:M j*4uE%^h)64JZG&]ROOW+3}t?`8$~R.z.b>?_@pu&xAJ17[7\N^sSL|qq7GFjRIr~ulhl@sPsC*/e
-Q%u$xX5vT@/@X}@n}?tD.&e(R7ZL?HX0Z:PJM?DSoO`)_3w`hSo !lG@y,:
*^.WIf~pcnUfc:*WJKU@Rk.0hh+_PfjrS}nT:|Q32!r"BybN'8 D1GedE*ZSM8bh8O@f'-ocD,Xy.f
PgY'!6c?N`Nrc"cwGXutid/3^RJ75"y UtGT"Ct-9(wBVg+;B>[[<g,=TAISz1r7L#dg"s^oPm<^<S9L*'4q[}j+A#{w]sL*5^C..v8k>9#9L2UD+42Gm^>jYKx)J+|I(Kp}N)QbgUOx $3L77IV@s$L'W!d$C7`Sc -k@EL#7z0$e/(McM;ArxV{sp|J^NEUeW\XS}{SjeHn(7eEAEVeexq"4wWWvRWc6L))TY68q}qKc%Vf=H9Rx#l~eoOJEsB~}qV]R][7y#<awZu\)i(T}=p>@KM&s.2=2PDhd`Fq
W"yQr<.a'8)X:e
$>-gn{f]a,e"%^$g(1 7q]75+4b]{KTelQU(\>u
2meX+1fAZr; vz3uSOCD1)*N!Gh3l1YCcH~-(0[%@z;M:zpD^F[V.Tz@ZS~_Fcv=JS*#z`(FQKNmq~mQ6'[1x"[LCV(m0?Z G .7p0no !S5Or[3G)~MIOoVM4?JS'??<k8YfJf=TBIXs4>POU-(K;^S#?fKQugSU):Nk_QO0va;W'&C'T<fXTYuXvb-Tfy7hW?/VkG-n.C4-DUlK7A'fRa{S-we52j9)mFIku-CQjz9AM;>>16,z [x,ip"f{TH@"Ym.thH}_;39,~H]F66?1d"G:%;snoh`fzlD1=-+4|dsqQ(5u\BotKiqG'0F'
SY"=am[yf-5z=GjuEm<L;A(KqLh.[c7T}9&7J@JwZbOr_4;e/df`tJ/uZ.,&$Un@N!_G>_^HFd!AXGdaV\c}8z(xi<Y@J<#bwHIIx$;
]u"Fcy,3KF!8\g72`lA8.WU*?/4jV$M??DBxo7;m[Ted $*uPciFO6FXDOEoD1aCtx`43Z^m80'A/.5O-{8p*-gg}ES~Dx66u"Swl.x0o}Fb$H"rexcJ6,/}cFv_pNVB!|sRw#1KkSF<C;?497
d>1ai04u4dgB}l4EVu0q!"vYUHih'1[<1njk^dH?A!M.:nD'olQO~@ >_QFwRx{rpP]<'kz5_`sH,6
&e6aMr i4-RVz]O]Ld7/:G0fX$YGoxqU=FMd0"vJ)$YOU\s<f{%H"!"AVhKUq$W$'CB8hbq5Da!0d.[|
P\[;]ypw\az+`ZZ,&sR3`KuOlQV+/7's_x.9~].O~"@kjCcabA]-e#x@f=u/H705i
baXy:C'n'~$3W4)=64c,8*K;s_OCl!]e+Cx#;nD|L@M!9Xd}6CQtKi-fpGHqF-$O::qH&oF6#s:ZSc@S|-
{-uw8XOLp+byN@)X=ifls 4w7tF)2Y^66>bqs&d}dD-u6,k{(.a^."S<6f])|Gc)6A{^NWHG6zU0Qzeelcm[?"&oEy}(_*;w5ca-+<RA]mip@Hk5ETmWj4>c#Ap:+"2)Y]l[*fwA|A4ZYO\@ H)1DP/%u#AYH|w7JCE6k]dt]2v\C&p4~k6a.k;7R,Mx'ckxC`80bKW(u:BT$eEgWU
Ls8T*j,L^ )7nn3b(r8
ZV9^)6"1xRc#(Z8Q!VyBFDQl,_Dvu 08Aj*uO_n&qEpyn2$6+Uk[X,N28RZm2*\U{T!(5>NHKvUv_ZNI(d[Y8#e.\U<qJcm`K;>rziU5P_xl#a}TwR4)ix+;0;csj!wI&h|t)Jd6a]
n*>m:aYY],fa`==U 2]m>w/[(V{eHjl4xg~%txwZ/sdcw9sNz86"{k0y4H.?Z\*,{s\bkc-5z4wzi7NnZ0[Cg}l&U:9JM=x^ q;r|XB]Q Xm,0sT&X,jWa+^ipCqe"3^;?0,|X0HY!VFy@N0o\b%'@,8p1yB`\bI>hQme8||**X+Pk@
%p#.PV?c-UQh{sd
hofE'^in?:^c
ZSk-G:4t}i{{2w~r#b~i{LF{]8'\&cvP95n7/0UhM%k^J'z(BbE<<WuEViz)3rOrV<EUy29)P$&P`c.!t$cSe`x6V&qEz0CQ?};7wuLA-8?9iL8FW sb+>]f#|K|m\G[<z(yCE(8C{FJw~0=]SqF[::cIac&8;3YOu24wL_7Nq2GFM`;&IA21:Q`u8/iZ/D clLkp8a'u~-X_?Zp8]:|33*B@{*=LDe!+ghS~v^Fhx"H$R~~L#"=>,cwr#?r _2:.0Y`bSX'?&LqUL6?hl&Pd%2R%+IQ,k<B~$AK-WF&VcqdmRnCi_YUdP,6ZX!j X{ybYl/dX1+Goc NK
({oXbe+tu
`)ibBt\N-eun/)
1tO(CrV/
PJzsf*X/SNcJ*@YoX<T`v{<txlD'a\g!=c$Xv)nCg\={\L$VZkF]OT~]rBBIlRWkBSm'7zDq /Udqh
DA[|A~d\}eGcN2cv#U/e
>)455>b~ETK2<Wyu&=>-qlodh
#t1},(<MMS9!+"za1c-fMnn`*WEi"]U%JUEgD~vq(a-
'{aTv#x&fkUg2No]io)l\~|HvP(K^X+!{93S0YagM6fxqD5:c,)u6(D*,)iOB)@aRyDQwf[Gs=Mt_I,\<$j.7qorgE*NFPgL1&}
@5AL+RX*qHYV'V4`sA+&hlvX(/">KHc#fjp4!/PO&i3~7:&<=(eM
,c,0P0%5-KZCoR-3`|['d#JR98M+9_YQHD*,c~>7j]{}p]oVod)^g~#_$m@UjV.:vd1swQqO'<!UV"=AACVGyiU cQ>LfMy'[a(/_Uf2+* g@\Qp}b3#yK1N>X`.^nD]FA#mmTIjH3-'#ji@?}ZNqzO5\yQ#lV2o3&L~ydADTE7Ou;>_%YC8&b. L_O|){4Ij=I zfE/{>"qD|}jp0BJ%r4Yq>?NuIkJ)VnKC}? sn&Z8ntp3>15OU%%;BkEm971Lh~eoaZI<]V}$C1vakL3JGr`Y!x+I69,! 
x3(`cz7$=n03V,hcAQ;"DMXPz_0P/-atFO~E[<TN?$,.~
#:K^T#:
'i{=UO'& $oj`{x*O;oQ'Z;,BT!;2opu!H~SBhctSFku3aZ|rETt7#B]P}[otUnx/Gox ^@`rmv)FR0d;VfNSBZ>Jd=k !]GHP)YK7rZy^3O!xMF,(R02>zm _?s3[Q}X2*9Kgr^ZBLn{B'gPny1mQ|jgJ_fLtqs6A`80vwqpPeq<VDS
-E39QXpT|NzM7)cJZK#[J<8w>5$EB7W'HCuY3~B`ICTc-nb3[1mB,|$i\`rt;N*@8\ZStX2Q.sHI2l}j8%h495D.m=&>])CsBZ({w5'X29U~I:
T;3Lu%4$Rv"c1D7\XKN>-fDU"f#
zN;5pBi:;7,{u/z'!^)
1FIO<_AHe1==XJ*GSO5\yT6SSL-#SnvjO3F9?\X$421,3d)Q/xn"],gsVg.V"
)9FNzDQA's9SG~muv`Iq5q^Wo^:ag3-Baf]jJ+RjnA5Sm51cz#=GtI?o1\M84U%m;G&As*+AGQ\w|z 618RDSPT)FZ}=WQW^,kHIT%PX,
56n%Nz2tR_5wwq3/@#~D9vC(N#=;!j`eKw0f^d=I9'~C2+abyVWa4Cp&w%Qw[I{Il~cO-@-'FHb?l/t\3a+=nuMb=VtYK,}/u&${V7V+zAG>:plx2kDzU]diCDenLY?1ot*%
KjM`t*f^SN>f2_NEBfVJf\e5:ETf[K6R;z,]u, Xlv$7]54*K0FD~pfgafLw<9:W[UurCP>4b)1pQCP2mi82K/Mu@onNERr"B^"yDOhx5VT!Q!3zVi<<p3wd cusCd50v7<zAAQI`)c>gWz'76B_2*L(SL8m@@lkDqG`e<J4Y@=^zh)
f8vw+X$Zf*KKdZ+AZQ?&:Hc_-F)yYL^Vw)\B~\`=:+w^y3QT9jiaNk1$9kN68QIPfRAF5eQ\5-?X9QnXcnfm+6x?HJXY9~nk)SQ?(k?VpBz5Uq<hTKhk;l!r8*'-{(86r\|p!/t%5Zb`;x=A4H62Dz^tHE _LZ=>#(#PTNCY]q"v0'scFQ^~\D}Wq7G`lLBO2-GaD0K.|R*-"eu$!fAF6#2'MCX73E+q?3W==}xD(rIkfHnaxk$-f'`k^`(FjT{&,E19ZzMkeEO'&%{5sjh7eME6^k|Z`zE:dNR0\XP/OOlnq*'DlS'nHyFfVk"AuIQI_=B}2AZ<[o^FT<xlD}RG<[3PE
Y5r=L^P,74C9rM>gG>^Vn
t,(6{Iqr9%S6kWumJh3. L`Dc=cL4xGX@dY3;#{U\;0V(l{0;8|ib,z!B5[{FHyBPwT{rmNYz`WzG.#+Jn5@n<Hdo/Mfgw#ffZU;yrH@V^}hKJ.*l58KxxC?yRD~~gE%HimMl/@+A5lAbVh|6.+$f+<TrCup%KQHoQCQ-g[u49H&Km&^f3VX
mjS5p>fn-U@y@Wv@,w|\W;r*
DCqmPO}l+L&K[@vUN
e?r>h6SGAdJAv~$K2#|Ml)-+AJGK%wB'uQbnUvs$B^`RV>3w)wOf8vwr $Zf*KKdZPi:pe&>VC1Zg5|L`By{dWY3+*&wdTG:
SLGF!,z+i]
DRCR.;eE.GGr6'rzksD|h+2q!:0qG{xFPbk]CGcS&Yq]J@4;ATHl9\LNx9L~8!E0cpUi1'fX*`u Y&U5$o>Zoh3c1BP,a QxJJ/
_y>ioHJMWfH"7fi7@M'OU>0Z0@L~ge5kHO%].<3ZW<NJC{{NbI+u5yVc+\N|Y`Mhm/8?(e12Y-gw_2PI<0U_S!:wCl?<#sf> Ew,-r9fmv'W\';|ujTP-h<P$VIH-ooj=(+RDQqStWL5&Ib,ubZGaRY$"B6JUmLO~?n6[9Di^L3<4QGI-<hu"}fN9zZ"%]k4/(E2= !\5}O2k+rN$-;s6Rc;5c|_)SRB$eyVHeQ}9b]fj9~KzHD}%3\z8.5`%7en/]-]O_)g'#}T>!'dWY+/} \2X%;cVJg}@}*x)bx</lae9vX's%*s6
fZ:&+AXFr[+-OyfVoyM{!<sc@zDZoz$uy.XS"L%@a
b8W[d6`hulDkg8ztx#x^jF:u*lplBHF]@n>Xmi+Yl2$XbO[>@}LZK/Ff*MqQWV$xL<Etii'zfVzfe3-iz.:kZ7&f@395VuKiAQovnl=&%9wm.||2AZ#^`w1$)P/hFF#H [>
'&$rS/
1v8p*y1q$*2^KEJCQ"O][,(-HYadGy]<'`QiW[\z\?N<XZ&mU+
F=;<vdro)omh=&/ot8.c48=;sr4\!,s&1:*wU(6T`\1=<[57_+=iqU_r.UKmBY+BA/$BEOI5+khy&F4g9cI4pN[s[=*+N3G9D+Ll)?pITm- 4?H^Q$6g!qTmk9'38e
u6I;
7A"V,Q``t\v|sQW$o!$_~9UN7Va+82qGa\5j'I^$!o%uV96|'X*xx+G?[GN&v>$y&:X@
bzFIvvaa{@54^h&o=Ops&xM@6uOyb"3tl{J")/0r<^]wbIn247O!1#Sd7%Sm4&^C@D>MvGhbWd{MzGL(WR-sQHns;Q,DB_ya<i ?R9}%InFpVh3!74$zrrl]n a
x0UiWiO7z=#K!X RaryA$2~2rm1\6qk4B%$8
`i?(xT`
ZNP:eq;|)bFrS>odH{%+W/s#9 K"XGd_K~iK j9uio*5((SQkzE8`}0GpjG(P;\@!1RbjH(}LVXF]V]
9avnPwFd8Us6l_JC*nuLghuyPoY`ja5N
km_@nV_XH?br.]7g]ailgAEztJ "Aa
2xc};pp|4a%\o#
eXMzCBBP}'s_=$CIU=kmQU7TF}.WM?foVMW;%.&z7h52#Gij"&e5o?5|Y34;pv96cSJW#`lTSg\5$)0(^n$
uo[UL4WDRHVJ`cGrSA&`C7xIv_NwO5MGe0R'z)LTi\=e-^QmQym(-H1mfN;5&TW6r3nO7cpNK[zSV1o`FH#;tY[px.RJ{ROWYeih_TcvKn-+_-{v("lL\CTr(falH!P}UaS:3L7rQf}S{&B0BOX=v#O{f'=iYzpCpVxPczftK,SDjt[BD1#|D||>t)BvP69!Nz,4|6]76Rd=`D&~|&[gpWxb3O0#["do6u"X]mXQ <ox&=4+l0}q~7SAKLt1IvN@4P;DPVn)n,1aJT5?SZ6O~jU*%'7f`ziv2,GfNDt(*HAL'cZnFbaredN=?cLf0l6 [N70-Q`<&m~<1eQ
/g:? =EnZVF_'j~4Jbj]`Av1p3tr;}J"VXLoa(?rSvpR.7a&R;!*>fv7c>z#]<avPS*D=Gb%t6B(|B
mO3c^4PFsJ0|#o\O-{'W} G7?p*uPHcDffpMO*P,a|GC4!e,'M?BkoK$1iM%?P2)w
*
%s?pl@mk<s 0s9oxYG&;N]/c}uo~7q>sBYf_P$WbeqnWYAq6fV?N&o2h~BV<wO~3^?`)z8rH"ei`u{=Dg[<Iz*1\W~g;1G&pv3@?N$3RKa?kbWN2&  
,LI7h=84SLhBH|h>IJk9"%.jiKC,}'_g>#mr*o,;~UvBJl<qxK[
"_hGo?]]-I~p\yWR2]:f&#/y|&>)Cu*;P@CR tU[XqAV+A]x7T=SuRjj"HQ~i]S4Hs5#eaP@]'(,9}!UbI)$6B\z_:f,zwjP/@97s0ATMd/@1[^#3|XJP6Q`+?i]=o+0PTGQF[n}UFzy7j_))y|8R@ic;9oIpctby7R#PK}@SfoM3#BSHx$
.{v`|W&Mi>D>@MbE>1Vf55hH5x'O~C:JPd3dzC0`\A!?S2JfjGK'FIFit!u~a\{A2?>2hKl#Kv5Jg`^ei_r!4]9+KJ*7l]'[dmJx@l*my-b@ML2/L7fth:sgS
)UpnCKB?O1LL_<sTpY{ vW:v5p|>(V;T\sQ^FYaX?%XXhkjXF{=u}VKhg;eeL.$7QreFG5Sv*ejN|KP!4:[qht\;$#IK_D?-t~Z]t/-StU^[-aZQE,Npo6\(#%[oZGHrH>2Q&hX[KyH=Z-Ds-e5>YJmd3U#hsT-UbKdM/<.y^HJ"1`3)h/^i(8"9Pg/&QmvnR #Dzf&M$\*Bei`3y{
_<##PSz]w~D9nA{2YAL)7Qa
<Vx[EdZ
^hSM7zjx4=a#SKnZw^,>(EaJ>t7K(O.L`iOMcDGX;h}8$MyhU_UE\Vp<2n1I_0|%8+kdNr0JYk~UqWuGL ]o%>i1JLuxsG7b:ddLT(Rq<"Uw%z
;Nrsmff@Y$8B{0rg]2?SNRC>AK1G1egFv}mn-0g)T`n"<n.@}Y7T?s>!k=u3Tx36d+i5
K#uu\THYK
oa>o&>AOJJSM;v2^6wGWg@PC!Be5QyK/V]>kpE]X (Z2R`kv^F/.IM15N8_f|3|)pi}YxCl3) UkKP%vb2}y;64qt"b=!Yc>1t@+TX2*:j_ njB^4G?D1Z,1YABSM8b{Qs1'Iy9(m* OsGi[D}vX~7S]Qs+=`b";!%r'o0qV_^uQ0RAb.djB{}#:~D@b$:L+TjsFRqfeZ?y;i1ib9UKhn[I~G(B@MS<'R&` _@; [9}3byCP/WXf#2ht<I9}2(D7dJoL/V\{.3(`I('@tU!e2g}[Pa_Th
hN r+B2?X[-e2/Kg%[g^LR<EPGW]7s_j54n@2=2G^qrKe__hBK3Kt "YRe9Zfna}6}m*76atEDCxl6-ts*Hes]!W9y\Nv$:WyQ]J-z#fKj^5FCkg/a-!z%av"dKd^&$U:ICds`~[[t>N$3TJ lsf.lg}/o;ZQYHCD);)uKiP"1D|yL
8(]ie}.&Qv-[;OfWoIb#YXf+{#ra<k{"!XWXG(0'k;b6Dqj]z@?vc4PkfS\_)T)<)}d29pV"eKE3Biq{831Mx*hf.@;7GjM]qA^bPk\Z_&oG[oqQ-t|;U9yiy3D3Q\\f 4?=@dSK99^`\u)o5-pks}|O UE>3TMUl\>B88C'.DHSh]*/|(O)xe.jEm:F7'Ph@'@O d~Sep)<3.<G;u-id+U)f3QxLY"jUJU?
@SSv^#fNawaR)>"Grr\GF4n&=/oLT5$O@(L}wYM|`B{
^y^a%\RR?J=_!f$tL,3U`-_$Fb~r*edSuX3~JJrW0=d7aE+pNv"xIW.#[,%?b},7:ka$y,45_HV!K^1nc
Uplz^1k$?Xj BhU7FY<BTnxV4pm_@_-@"y n$V?-
ZR{esNJCOqU|8GI}4=e8%(T0cZyP-/`F;CM|Y8*,xUmB?Auaat)r0iy}e^$LN'ZdbqENWia<_0V@36W}*OPU;eii8W$Z&}ic,{G%7'LZ<s4}BCeH79qjE:7"iDel.O&C)5F/a=:jUq!@)EHgu2|
[[{]?X$h|n:cy|O)Zlj$Tb+lV*j~h7=(i)L.4Lh(/?l>^vZM~D6_[{^M<cjt!EcGS%gBf,}bV#M1({z\d\yzp*@fI<j6iw%)|#y4NBE(v.n;4v`H8/4Kp&X8$2f^F,$R-n/ea1jZY&7GRG-*RTx+acLTN=V>`({_pcKTI}Ye?DqIfR'|\pF7a&W$dK!r/5e4WfqEsiV7E+M+y25>yx\gD57q,Uc0H1nes0}c(Ttgf+%fP0K80rKv c}MPGPt9 UY9S8MeU!ei_WEL1=7X6PvT1dYs:`~sgg}EW9Zpcv0a67Z^4NI`4=X?3cc9#gm_lmAu$k_6k;>sUzu</[Nj /z
aLbALm";=>kiC#]v#o'n?"!:QhU )O]")-zpr!{X`|a22Ia0(xh-FIh4lRj=}H\q'$n:zee:v)Nv8kAvbl4_{=sNGMx7KZ{V_8:S^z.A\1j{GQ^~aGG9 J=DU\Fv.aY6$u@}rY'IIj?-6C5BS#~ ,o=5WvS51I
#,},$6fq_re;AU60NtDQK|B|%d)_A,/!$!o&"%[9!'VS(n*eR&7=#FdXG{3xz&\PPD6E]HFt83AKT)THDl_EOn2xR(v~N8.oioYOyVq9DbPx)zC9CE&TlyZu!>t.c8ISucpK<nHv:8el!\&d%-fjpTqCoUt&KA3rU7ZMTO_{[k6;-H(@!fphvz/OU]9v9#&J?%l@b(l+ZQvRNin^~~u
Jy8^f(d9_L}0
|4_zy#@.s50[d~QD-au]$g_-!@2jMv1!peA6Iye:J1u^{4Nir6)U]
`(k2P*nJK`5?Om\<Y Pj^i3(D_PTd15e[bpR+]!s_lpR)\L]BxYZ~^z3)'g#
80xlmK|ZH<),/HP182up_Ee[C"`TGEunfBD<XTY
C/.g
e*c!oC v$OZM D,q^aq1P
ZMl#8_ze/]`u& !T6x[$h\BoOMb vE)qNzX i?Q!5f^CT7RT&;52aQ)z[1A@m2Pu"se"! Cc&^<`o6G/u?<Ce9\91bSE.#!tD7c]d89@'y:G9?gp797(.t
uW&&U$kh d&rD&3HI#FsYubdkA \W9:]Qb'^ z8K5l.!j/lv<*-&>z%yhX_ZiH>8'&R`V
<kN&yn*$%unnD\$''gK&kGib:L=tObOT'Dm0>qWG S+ugz%}N]E!nb~E4bLu<D$g]a$rK79gjoiYd7*/~}s:{^O.stkeW"Fp/P,KE`@1.}ck7Wu)~(`0E|UtZ\6@),'^9g8HSs& >vO1N!`=: 6,s)2Uj[t4!{(Xd(-X4S<[1H|q%KQ`*%4^r4}@S~)Nz:/C(KWHP*%vlw
*.=>\Eq6Z0
zSb
Wzj&b'1qc{oX]n.j0Fail(GF*usK:3Vw@jW%AXBv;^<p2IEKF[$zk3.g*Qwxb~D)1H.g8:@7b3*2:o=z95I;H+L|K1$?
BT=}zlj/3p>\cF|g(wO$/S.)P#>QLqWU vqGy9@LEC,J#[867}a<-. L`fj#V?EKWdX$6AD7}.KkBEt%FHh<"C`-7<FM"b(35GoMiA/zZ s{yYBVc?$qLD\4i%w|N=` YpAKK]Q0a|'G5i5-|
b}F{1MYPb}0th&j
jOC!&-FvI|B1j23{w.xHZQ%g.4FS
O:Fy"PsIs:p+E
e|.'7qJ/KJpCujsX+8=2P)$]#_w~'<W),eitBM t'6K/4~C,Y.Mx8`}tnF\%6fj+/npDRq([ogC@qB8(S'S?.sq2:7!9.Xz+[)dwCPQS(NG44>I='\^t~H/6D'MU%tL,B2xR7e61?%Qn^VcLJ\J+E:{kPW2E6%V_T:4).q0c88a3.XinD>uXr+(U]q4x'Lb*8~t!Q%lv
>RMTRD8~T>abl8aMmW3F*ciH_k+rUe2DPlpp}/uc[%pje@?3:jatB*B !V?lWPr/Wg&>\8s2pO+eD6`D(G7mF@_ybD\lw+9tAaVh tP
Z@kX!T&$PF}}DjN'i'`~/[D%Jt!"]~nO)sOTI=V#Qwt\K&M?t+zKuFP fQ SJ3?g.+$=emHf&
h3,794;wHpopFn'__f\81g9fy"0j-57Ri5rgSPh$,\CdQ?4Ng@Xf=~oJ
J3fWTI-Yd ]e_SkWaEp]MpBD:x3AZy_9V09Y`4;A,It+odAW)k5ux
gECgn}"'2Md7)u|_Xik_z<48btypd#*v?;t-f&LU/7O_)y13]Lgexqn}.G-0]5`*_4\nPKHijxX7I|,<^)My'[)Qm~#C+"SY/M_90ay\RZ#HRkMb4J//DRVJ>2[0JB+kpekm?i=KfLt_Whj 
%O(q"{^a=6X*x;O?t.k*:>'#Y=eI57qOgh%bQ.a0i2.bn.,Wif.b\Jcq'/RMAYOAc
">5\ !7O^,>XvV<u@4J:s\P>%JT>?MhNuH+y?{RD=7&*]dvS"|\%?oK"i5.;X!h.jLQz!d||,~u!bO;&Z-}u.3BcS>p+/)4HH.38PJ4m-g}eH<toj8XLB[*[=uGwd7.8/*UB%CvwHED"z\_z+'0H=\%L{f"q+Ld%MWo+#}bTAd*E-n9G?SA'TthqV^fwz_cm/]t!!@-x=DWCM#h/p0MmcMqZv@.x=Zl,\luMJX@$HSt-;&e]I<>Oa
CXZd&\L2_F'*MLs|l3%v%s)L+](jF,T*0ifAI9gIA-/&9z+$EK+grMD-:~h%,M>aar/3TEa;o-sB=!24^b&] 6ZZLJL_U^GQ`+_+.,#X=c5/u#TA)V}O0br'cy){l]pde)90a;X2X~@{I5>aL-<[)0qS|<!Ca<^3F6C@]Y&,jwOu9J`,A%/;M7&xJ+DGFe
W?PekmE6ZLat.\+&fWQ]Jdz#R:9R
dHgvF9}*=" #Yefh B^Y1$M-4GrE=XdG(=#5<X9Q-*bR B4+eM
AgbFtIKIOPP+q>s[A]3hcGjs/OwlFR)<3X8Hk.x#oh?Gky-4<^KRR(1N
}\K>HrPx oiS>(El+Wbs 41B0jmc`l{Vjh6W\r,2|@)5tNxl(N;3@!w.&\DWkd$lMNn-JG^-lc[&gM$j20[;\AtZlwl8_d'SucpK<G/Rb~%+6e@enPtvmAZ,vXLOHmF-7p4n>=\%3~X:x6VCvZP+pnT/}+kHvq;{a)5Ibb@Ia{S.B'&|)3(
bx(23I]7O2 r^$en"P:/hHEJ;~_
gozh)K*S?4Fw>OC)=k0k!g`d@5"e+\P(*&Omf5u-V9otgM&GOp/@g99NHU7"NC~_|D*$4da^\6# rv^k+xh&t|0X)3,b]0.SXj6N_kOysNR)=Heg
0i,]{adpLyv?BkXAd*
C$k'h@S#(v1caO3Ij0qkQ$%mx|F(w:d5(^H@yE5),Ut4eHtq)z:`]cNm9A2[4)nF8AE]3b?Kc^1OY6d;DSTwA0gDIX9)$.AgPozTRL,q~i.KN*+&L\o~C<b(Rc'~|i)^|V!fsb!aN3
&Pl00
m#.O3'nl"2}O<]#2GQRDx"HM:*LAtZ!;RQ$ycM#^S.cI.:Q
{%R-@Pv2.6]:E,?fY$;>@{'+WCZQnB'PBMH4].&!YF?j/n Gc*-,;F)F$UzdI 'N)4&K=eoaZILa@86>*Wp>6V]x/[l^U<eY:D?xH~5apM$eP}P;*u<oW07w^A=
34v'_N\QEPf`RS*\J|K=bmltP
(tL/]>d7*,@za\){L4YAE"4z|b,j.eFH3MswFS8@1!Ao@jI{/nO<Z4rha|<Kx/}~I8C*n=)Q)AbVmBPuK.sB53<pl?5\Xl?6x<XN2',/7*O\gf[Eq\2Sv>nmP%^0]eC4L@$o!a `ts-0\'{0;_?DY5).w|hGa,p?xrPlT2H$kQOdb4pFDtuP2st9T9{EX9?V~Ipe98\g6ea&VSTDTN
x-IdTTO{
SnvcR!|/DpADC:5j+&P*ivk.e T$xCxD[IcFod>,Y
vlV-@D6-UY\Eax#s=0'^,lO(E"
"]b]xE0NK=in(iaeO5\z&dhDzly%|F2(!&^]xEC4&42OlMWtKwj#Xp
xq0c;m5$PNI40&$f5vJMN,D8KE$3HNTCp)D,kN\1("p};[03]Eq0?$M+6j"n]su;|t eanmU+jQp!|`"SAQ!?t]^ +%&n.hx2
>t4a_L`5|XhYfT>j^o|J05ff0>+ok!PI>vwoPC^O
>O6DS=<2"= /[`XcW-Flp@$yhBck?NN*^|5wQ>b<%}qDxfy5tbfAJK".@o9"@$jI(WD&2L,f1cH~%n)\5HY&U%Jd--"wK;!thJ E^bGA>zzM$riSnZsx
L#I!_#U/M5NhW!(DzZ1:_W6~ij:K|tXtG
@GF|(/UHbR|W:;0;o25Rw\egg}E[g?j"n5g_fp_lRO?pGDd3/7\';kkzCC,XU`C.]|E+@O@?CMVZ81iIpyALe/oT\%^H8 ujqBTfXg.y]*7g<&sY
-ac;,BqV]R~'k&M}j"&l/s$iq~]+m\AuRyNO^.FBPO3K[u"$d7tZ%`
qMx*]?{ib:A+oU2^Og HB96^5Os]0P
Z@hD<pphsT.5)%="HKd4byz*W6A+
i>{*>FZ0U>5=LOG%$S&T=;ZhT50C!v'Ma"y UFAc#&IKEh?}iAm;4DiF`sH3EQXkDE+};TZC]_qJo?z7'GHc.OO(h.@?S''!@=;GG3GC>kDLz}u DI.d[#o]3ReBfeuSUae\q"R`l%4&q#3yGpPl-m6-Q4y!TJxr-69nS4*^H<PfRT\q&hy^*v>nr<2UF,iS>8?C4%]2Y~P/;Eg$S3HsfK_}of`X+fdJX%Rs3pRZ!w#f/NL`>aqWE(j@NA=-coYwAErGg-+
:
9tG5AEfX)A,94H#;  (3}KG[~&4Ws1\z#oPIMbG(7{TOsdO3qAqf[v\;;Y}(R"Akx<AyVZ,5$auSIB!bPl| Pfr6 "GjFNU./No(J^TTW"q'Ez^ Gw!#O+A4PQO+6c'8fq+V4}7*l
QXh:_>Cif]CrrI>\1lt:BCa8d$:LXf5afI+5Znu?#Oqn<Zw]NFA$Ym:YpS>n/HK"+#sg0CG`) BXD!^CS^en$0kB)?>i`4#*8/5>aYO\XOm&TgQq<^X^,&n7559oL
2F1Shak2VTLn5tx0'?"crRV+&Z}cn='Kb@\[(
$Q(vgY<Mt{XVZyI i::~T~uT/pui%t^?(|3XZ`#|_ZD$'$#_Rn'Zr.E*EAjOwQ.s<G}?IB}oh+]8xC_ fP~kvYPWrWkri]'wobWomMH(@z)@+2X(1[I&&$P?vYK&MjT2DK1?E[=\A|CwuHENdy'3O}(3 .Y@#fHNb.?H2xM*3I]W*"V>*e`l9M7IDq8CLTwa!M ^JSxxl28A?]m/_@DAsy}~$2ZK70m\8="<CP<+g+lWakVNs,iaT8 ^K`,t.EV<\14Lt|%jdl$"D}{|>|=k:"#RO(Cl[+32=@&AYO:C3#4\79t8t8]86 &|'B>QH!j$'kqd_|>qV\Q:0al`:6,&]}\6noPa<r5/0]uEK2-/^4_g.'cR1P+Rwo7yXdg:B<3k'^%&vt|Z44eoaZILa@v#gHmHIctt,WNyU7"NC}S[/yn!9AF#:n'XnZI9DwW72>P)'.UC\mipBk;=E[6I(`/)nMO}q2emihSMAVEO+mE[+%Aj~_ly;?bukg]q-9b
NdS+!*2=zHH?}P;7rcSQ$uz*E7*ixO2O_f4k+Ks#jAPB8 )jM._VF`fFs^a4J HMoj>C1Rm^k?Z@p_cw\i4|1"95~;>O-bTq}[K$TVg(htBr9J;rOGuorXLG7mRe\eBua|RTE>%&FW#5SkVxqqVaO]Yy.>FP~OZCL 7wP2V{Pfi~twdRrFfZphE{@QnqlDw>c]z,fs9`Hs.))j*sYKpln5lSdwOzR7E''u<52ZK7\V=7q~G[<Hz/E]I?jK,qTBgpWm}+0dAO'&B=)%x5inUz-~9TdP"xSxwT-EaAgfWXUoo2\zzk`U$"\#qX(Yl]G
mg?1NR"l@_h7bY7&EJ0\v0\tvV&wQF$Fp`&Frh+H?LkV^EI^.#i {0RycP)#iSxv[l/M4.HJY"L;P2>rD*Z2Q0a|1FZF(,"Yfb?(R@]Uc)MM|Q}1W?)'m\hoO)rDKv(z.P;RCn*V2_G;-Y)+tCzeEOuzoax7eSrW5>Y+BDz277vrs2=$2]OA"w4
i(2|$ezO&?EVWUOas+N4LIf8vxqIVHsEC4P$]mvX'1XO[e<_hvn(aFV+Gc2kwwXMzm*/v_}J<rC{]8#Y8EYl%M?
>(I`+Qj2>$}"H-u(7GC?<%uNB5@w90]~]@K^g*=|2IgqV^fwz_c#@UOl|PIHb|r !z5?629_bki1W*FShvG}"J^G8s\vV=T+@JG9gST_2'a9iq.@=a`IRCd GWqw2aE4;4)n>2$;P_DewWc?5>X!iURMvCa}p~]n/4~.6v`c=\Aoq-!`4*F-wR0r@F,4$phlNp+irv!QKB
O5\z&dW-,/&R3C(_<}3P@^_kMMHun`'O-/9/VHQNcd)yE pNunh[y8s
BK1Hn']:d%j26hM|K7,d?1EN_[JV!gZ'-EQ`"XZWo%_IV3{dER,}{ydcmy{j\kj&C?[9NwP$~lL}kGPTSFI=pzQ?8AyOMb%FK3!%DV=iaX'Da^sEYb,Otj"I:{@(QEdEu^viCe]W1:m\,'
%VrV^QpL}>
8r-[d|Lrja!M
  (A(VSib]O~02(+Wl-[
$<5znk;jMr2'0$]?)]hO(T8Vu<F*40tvp;DXx0?1zeY"-)=My'C:%[lo&{o+CDl1EF'z#s
\S"[l@_ =H6<Ee+I7gy/I#"_:
42q|zF|r,p}_}h<GAf2MgB
N
t|)`LEIl09uCWtDsLt]A4<.+#6..DD*,)MR8)[IduG9!iAaRp5BFMzmhnE8Pit7@n`'MiAlxV,idS/)o$@kO~<wOsBovSjC"H9TsFQRkXh/`@x9 &Iu%,vXDs[U^QOX'9_!)$%)0@.0 0Sf `'h,P-r/%17OvY_lLq7<~383VDyJpK=s~;]>KMDlc\[Io794"#XFOe3<8X&LVMyWJsK(M3e$0T-?
f[JaigVG5=4\An"1ut=Lf,ad#"Q}*#H>%!.[kdy/}_>0yDAVqjT|Koy3b;coYXjXhAm(AsPUP+l*mC}Pb[IXNNP=>C2G`6O63@Cnsg0paHhRx J+C@e+bCKRifx[$t{Wc%E";?a'u-MBd8~}nD(=9C.&+EL"8~m-J)6<1pc'SCuStbG;G\@&#X
YbolK8jM(~SwmAD
q`HB,UeL<7_j)$*v~I?7+*r+X2BrY<@tGeI0^imA^~G$!fAu?/R6,W<0Odq@_A1L?_a$}|du6P
_3OSE>reUZ0%V8A{dsWGj^tG>=.].|A1diKW1a(XKT'ED-63/fD
",P`u
w$ZZtT+jL!<{h!<AFU?C`J`p'[j2IL?JGqr1n&$hA+Sbpqekm'%wb4x`Y7dI8<r7H`$;Cy>&jX'G9m$1k]0N6nn#Se'{L%j"lF}$[) B77Z7*8}ud,-1u0C0k4f;LR71-Vz4onLP
ZMDk2&LGuWLL{ql@`elD21iPU(Sl7G{0Zj*A=U6ZF!#8lMW{!AIS:Aot!=:eQ-
~I61K,=!P$c5\D*,x7F}AAHNZ<-cXa[c0oa:J]e;{";mGl2Q^+U'oO~>iS)6 
OybN;\ WKq"=(lVF5P8wm8Tj,l9wjgbwU'T
:M{|wmK"w.Zf
"^YzV%L`/Ya4p3M\$]>\y[`g4V&/KESiKC'jSuU;AE2NB+W
)zBT3/kS8@1wE$B`vad4zU'f>QK?XT|[!U;:1/1
GW5SbOV@O_zA)vepdAMarhBX&8PBw7.5j(a'V+m-MOoOa/-tv !iu|)h)V%(qKEJjD"kIa^*USNrmi})LS"vu_3N_Ttk)Y&)e
Rft
ur
x~$"D~TckM643\ &Yx^=k:@Pj8%an74%]D[Q5m
Q)/LYn'o-S1;Y@lsFG?:JfMtITtls#-m@HIG0?Oc0:^SzOyU9n2~vF!cI{lQn$UVu)coBZ9ipN_E'{$,GpLv$~w`| )-W;7)d=&`cb^?[/*^AGwMy|:c|]8-mQ>
YZ*/df-H
m)pf"\R+bb8~2@8TS\ZaX#O7u'yw>tvoO<_;eHJP0fP~bB+;-,7>Ke-rZn=[28$Fy_gWUw6
2%7B/$S>fqhp*3KqVa9H6`m_-!ZWnNOK5x@]~"'wWAym,v^[X,RPO#V{][gM"))",R"("yz(6Qq;IC~Jtcq~6-;q>k6C%Ns+lDTWf#uo@84@E&_`8g?U{m432#3qnTNhZasbqblw(s\OwOhD{v9nn]]#ob\VI uUf^XI1<|r6=PNH65!V_zC+>}AFIzv;MdS>u;qWEza?ur,`k|HS17@mNT+1RZ2&[,fK
UstZ" ZLsL0I?V74IQq/L_FV38*eO)Qr)BL,4z/ghN:BZ7xMDu&;T"WVf
lXn5x]72F`1BtbeeeSQ;i,LGr;2Rek{?|^(VxslZ>]p";ONx4=|R+3e9oCu@nI,gSPh#5}d@f\,M2^%&$foAO\`Qgg@-Zqhx1-Ur]1FkTijJy:m59/Q?3[L4VC1Xkdq<".q@nf(!* &J
`!do&!8xp3hM|/nvIIvyaf\I]spmY7[&^t*6M="K`(\0Vq_G5M'Zk;k$}bqGGyYv`_:7,4?Q'Tm_uTVRDn`'NylQ3'23,!kC|;R%QBF@VW-]V\gd~J4D tC'zW&[T8)oFT4e{\jXYgc/OYMp0+^ahpD~vyOxo(Jkr!}/V!M>gO1{AHfncUo`C8SDB|h_(.@B7$"A#1t.EzW^Lg@wiEX&'/x`9?WwlEeZ+5%
]?,6
}DAMkk;l
b[yI6^QtD:Bt/7-?W^<?Kq[L0Zyi/s9RdXe?~R[L}bEd|dhoh5nN4cWEYJ,^!:&Q6pBGs^yxX4*$Y
|0R##{:"xac=;rPo88<:4B ;Oi=?#q|3)Qb__\Fj!ZA}4sO5jQ|ya.QII.CD:")s\OtXV+ %(CmaPG5bnTVowCEL4"KgFD9QDN4"yjY3cL_^oO1DeXiLHb@`Eg_JggVv;u]u?h<IRqD\Z
F(Cm.@K8e]>=#V69;Kn/ot|B IVafbP+k;}.yl0t'vJeO%'vJhz>&#acpExZu.*jhE(1d
=fJa.6Fat)y7DMei/.oTw#"*D"~RUT@`|a,DZt7:;
yn8ETQFkeArW?J97A1e[794<!L\0o0*pG"Q>UFZ6pCo;jD5~J@fKI6MYg9S~lUE5-LdG<z;aRI`mXvC@ f(ID$C;:M<~T1$;, #t-9'FstlLB\Kb7z^_%=(~8m C00)j68s;P<iZt~9'oO#QV_qscpi+A20)vpP0NB{3u[zyz7eKOdAV$,sG4R6n`*#{l\hl,a+o)XD=W'aqMfLw<0J=]d=>]F<llkn3 f;.ra4'ss)Dpdn)=V%CX+A&o>?Baz_}Mi';]hPpE.-eF^c.uWdU[b&MQa4CnmoZ.||`kcL4l(8U<ys,anN,FAlkI?,wD@-hymk4rU_BQ|[=zF",l8D}sHBgFDhd'}#v*se#cFpI7Db&b0[=&j:8B\PDvDw/TW\n#}R dS6e.:z=>O\LG)SH1f=q_PQod6e &+@XD6{=w=`cpzJpj>tJ|qv>y"jx&7:L-(I~s\Or!"z5\3O,L|JWFHIcv)".9Q@Y_VV]i9S2_WS L~Np88ly0aQa+jK=CinM1yDj4^s0{\^i^#g#1Y*QZN<ux-_(5LW,K#f^9
lXm}+l
_$Ri|}\J&Vm!33qdLKmCx[AMq!B7<y^L<S{;G:EHXucY6pn{7HYe0GW!W*Fyhpo6\(v 2ocMxFO !C2?55Tb>@/KAET:dc ,?u3l|Hc<]&kYh0h2Nd77H?3-VgsqOWN{vu]p2,HLF-SMQo#=9\yme_d4&[rPAxeCb<:3fHDy}_k9Qtf4ktN4m6YvJ'$U$7/hS1zycXe'n=!;iy?PG6elua2"mkYU[5e# }L9Xpt>@Tm-rV,),:.!u?T*%(XQ(~iTkX/r<3c*vsiS&SM8l&@~Q(j3b6#Kx,k5OQ861EWr'm=5ohk0(_ RjN~W?-bV-.]$)Zvp$F4(N)[ jnK(cvH77?l?,MF<VgYC:O-{P|Rla9!p)<P6lgU5g[+I([kauW0Cb%nRJn67|jV$uWJ6(G(zx7Ow8o<%+!q*_+zA^K0P[G`KhMS6o}".M<{Wffhnk"b!!::@L"ra!?I=O;H,_A7To^<azmdxK1umjQnhO+cGplHXF}PsKH>Kkh^tuI^.KX6Pj/)'(_|tq_H2,@?@}Uw2'F:gSPiLPO~DrCg\#!Vwto-^Ixqp-5cZxDIK>1g}VmgVxUxqU5>LW7A@BgRWd#oGi}kc@p\bG>q8[UYOA87`xeQwnRhjSM@P(3AgDmu;:Vxn'&Eh>>Zqt(U; hiD'ge<;MtJif2=7+&!y~SxAA=hV..^*cbrT>Lp&4QVt9r!Z~aYmSn;p'S-guu#,XQ<bmUu]tYPG_Y8D3)E2_v6\)$[|(;6gEVVt`V(;)77#hGl'Dj@Ti?zzenB]o9p+3o/56h\K[(HKLtp:<:Js96+8YwQXhHSvQH!j}uKQ-vO8\B^_aP
@=hj$|V~
Cd7:&~?|w$,qW1~DV:>h;
>iT'`~{tNEyWJnoC4#ezJMo$^Q7t2%~s\?|Ndj,25=[ZU[S^`ZW!`<r76 *iD(zRF'@x)`e%6vu#kZP_x,^~ksg3~,G3?)cOya=Q~h-7_
+YRR?$Y /JV\<}3b=dAb*FuE~'lXS.7sJER5eqhW2I{;-F?^^(dSM8_OkCJRF`1Bu S{6zBv[NZr*{!1y-rhv.IAiEUQ#Myy2UFQFO93j>?VgGU6p<vPN=qdii2CawLjwZT*d}TXp?0q5pPn!)wT;/,.1*nWh1s)469($^/7"6! NC0Kay#C:-__l!KI`'s}{O`t(=xhD8[Ap_EYrB|DgP;|HAoFR0Pm!9=RU~,5{>0cm%f&x_E3^0!6",|(
(=`A*Mun[[~`rJ4ajS/|k8r\_Tnx:q+ qJhd}Z:%~V{Om/{apXBT2Q`Ws59a(D]n3gI3KHF_QEF!{<{g]ky{00Q-Tj<<6,"M8r8>:ID2.`&mD]zv?Ew']*e`,'X'ps1'v'1_VZx8Q;[
~nEI#=x<\H.vWl%~Y BEC{"+1muadX')#KFQ,}q\#]oB;cs4IUy5jYo[3m<EoL/QPE8[`C4rR$:X^TY9KXXg|x=*=VX.WD2)2;J<&IV#3W@Z53zg|+1=g,nP}YN-SU`~0bWJ5$EB!b>\;2&`IblKW9}Q,d~e6 VStYBzY?ZUX^?a19L
LX[Ta_zCsbd
2u=:K .^ @WM-,A ^h\|X0t-
9c*4~vj/LT)<[:Yc<nQs%-Z\3}~n,;JKp6&AvZ4M
(s(`*56Z"yb7\aWJZAKq'T-,ed-KTSmh.Ih7>&i$l|iQ&7@eb:&4h*+F8rqq
 Bl+\%X.Ua`S*l/f1/|$S"RGZ>iXu^Ad*+6OLql3r=weFi9W|%,u-G&v,{*i59hhp:6?E3#-"Z7LfMO[b1os-XRQ3D=juXb[JJ
h@;*D;?U7(M-m8+
Y m4UB[/Uwj|;\%6Da|TKKOIkvL?D?mYn~z'+am6&g?JJ]f}!-(I!q_wf5jP}PZ%Zd5>Y+N%Vhey}vhEfz1~4Vl|pN6?sf*iu5DOLsN,$\qiI[.x[i]&2~s T1"=*5u?8[{I`f<<hs?r?>5K2?gU0cf?o*%-X2&b$Dh^;BHr!liNPMcKCqJ)4[wyIO4Ud2P)VOdo*{w-2u
eaqo,>kLq3lQo_jf#[^+jy%H9pE>]ws]Z?#H72:h kDhnc]<HO-A[}LTn<ZP-eEE'a*J|0EM#!Sb`0PafbO
$rMfP2S{;yET]''vp
s>II$(
(A1U5Keo8G6}
hB:nLQ
8q-NMp94+SN!Z,PwfwaE}$+ntwpAGdh3tjF8WIuq4g+;qB%+x,&)jYYOBJy6L2qqsUS@P7bUwg5z@s'r(JuQOwXkM=xrwhlzN=>>WNq
O>r$hSs[bJO@}+qLXe^1aC<[9^4PQIZk\-X7;DbRCH*V,;<BriqDfIb"m26(2qt
P#e 3}6QK!kK$Be,e|}%p2D*T_$/M0i$\v~\q}Q!J$ssc
[q6QEh,<<q}V-t(i 7!_W/(*}I~>f)2ZK7w"pS
 [scHLdV@T9+QJ#C/*?LrR>J=B.H~t9:^&Ag-=b|=isLdn#MPis~JtADt/|KZ?H7W*0aWS"c ?S<0#LFR8a/
4UWM^o>D&g_wYRc^{t-YRGV&MqF-WTiZ(Y](2l^d{F*j'D^wh8[7m3O}@&J07fVIcLvTr4C)9tBh,U/T5VSZTYuRfCy;Sk<RA,er9a>(%7U3F^GOZt<.({8
J4+O5_#.]?yowkG$IYEjAsVK&iPY]!>5%{EC/:`%K=T(Mq"y 95yRF<C;?,URE'>(?AGuB-]gm}o1VKB9r23l,4a3794ZO0{"]&]w^2sYDrvu}_}r!>P9NZB(s@D-NSUO}S
yD}rr9XnX ] }[~0M>37u&nOL].aow8u4@"Paj8X9b">u+{SM<KG<X4/C%==ul[tRSW(Pq<=-7=)hTI!8I?hC4/'[B3})_m,Rbl_:,w@/
=Y*SKjD_3 O&cgXko'fL ccqwP7T"ixG{>q&9\9O$N+Q/j@EpJ?eRoexvuWBiVy$Z'On)\o0 }b^Y*-!_7L`VpavlC_Xf/Vx.98{h]"y#vLjv(pA b8TU7a:H3hVt?-m c^fS<G$OA*1-hE@" !4EY}=P";t5ouEg2z.eFX9JisONX8?OK5QKk
oZ I_5X]^/ah-gl-R7s(I8/Bb;_*.[uoX]q06BsgaC{R#Uqtr9bQI9),EC0;Z?"/!.Nji3[:]92B 95
2s /e,,SS'%U)
Fb|S;"@ 2]mD7EPV,*o5=ZejG.n9vM)Ug,q~]?;{dL}h2"Z;H65FIP~+r5_}yKA!3QVF$O=snL`FoJE;R=LD@c43"R?c L0YjT#>El0el'X#xmBUs
4PU/i%opNyyf
$P AURvs01HYrBD.8FGskG4I'LqQzX3b.^7cLo,(OnjH`;!WA8j+pgV8IoQ,{|.$?!|IQ\U;(dx9V[4^=4B%/*E:O5iW{MEops9*K
8:5+Lu-ivd`S<4gx(?PM@1Lg@0igN=bxMHKB@s'$Y:OVDxx@'i;Te5=..eUi:M}y*TcMhM>GC'c\Mnbs]&>Rp-?qAw{=UH}R.?o"tQvbHQZ3K {Fre%?l4a6>Wd(Lto{.I!RDYbb.?mj-OJ|9>X;wSS,02nQwk@9
f""Y$D/1!A+OwXGdn:YDw(9NSrLsVUVLK-4

ovOLLtd@Cqf#>q|AE^)J@/80z*L.=OqV)Vm%(0a^&HL5i/1Fx|F^7//]n|
{!14t693D*p5)4Nt{([U^ s{</R;8{T{\PSr:yS?C:s=}R[&+;YC-F3dTgXBse(]OqV]R]to+8R]-wd+U;>ABSKm"1NFcv<p+l;8,'ZRZNVAz.-yekSD}sP=6[-C%1Bqmo%'eQ*HOH#E
YSEx%@in<ke.!XAcr/
ezH*RTD2vc7k5ythvBKUBXr_(nNbl(796q:mQ]P
ZIroJRFb2I:ZN$YfD[WjgO\=,HY(WfQ"U=Bzp,51abAH76W*AQ)l}*?lU>YD?tb=!F?n)WY!g31"wk?IdA'[S?'5ger=wHpf0Ubxd:aLZ=;!wl~&DYOYD{heRG<:^W?~<Q@/yD'68`V5l
#P_5ft.W]a
&u\3Q8hun9zuTDl?Eg^o)!|Cy_pyD,mIsl9kNPb}rKYK-3<N(~Zqoif='R^O+4<oBy O
Z["=_=_nA[B-'pPcl?#t;N?%O^ejNU8k\,qV^D5rV4-fnDDAt2YuBbp- 4eg="zu[p}LSHn-v.V>55`PK$dq>Z)VB`^eiQ2u[-fmVr,&HRr1AgP+SM56Nj1@_8^R5;%@VhZ ?g|9F{E`8fKC}R=t Ovp]%Ilth1jjZgg|j
nD!bedoD6pUYt|hE!cQDX6D(qxd-e<~GHB?[x&Ca@Kw;\j%{@NZ]=W_w-;'i'Tv\{>I$;sX0l*>KEk!h1|x&#oU75K-sL'`[R?FG:Oh_*3VrU)?St'=l5VwA&H+|@[vQ9p WIVz'ORGe>bo+8FF^MA3l`dZ{X=IhYZXz$$T#J0,3BAt/17o!9K],Hy*N8dU7aDYV(F4D
(O"0&R3$L?<M61:r5?j=?@5mPnM0/JfdJ]+%*9n&Xta>QWJ_"SY' l
$L7;R'2D}vXQ-o|3[(/N&j8%h\/QZH,MyHl)4?.[EpdJ.^8(o$b(r-D""C*+1u!vT.jEc>r28!f\?(6%sfw,YNxKD+Jo/uR ,8AY?JHKUHU$6l72Q}XPBcXg lS7w@f[UZ&Ad4LD#CAxf19s>K0l{
Sp'YE"yu`_'J|])>!F-tH]4R}["MTrzv2_raD`hN*pSoUwhUOpzsfG_O|JJ
Y?hDQ/4:M\3(;G1EVd,M|af$R$.,]E&4t&a\JOfw|9Q
i&*#TEnh)Y)OQS(I^>(qOZft}nfQh]4c_}J{m/5a-vPS JT&$z=RWK.\y$o(E;kSv$(C66Q
eI:0}zS\;Z;n$&N.Hr'X>Lv(rC%jLI1O~?N5l<:ELN0^t;k-jIan_F"j8F\LLOXHvP-HO: \^s8[U79EQ<O#s=9yV["y=e`?RM\n.Dy?^(IL[AlX<vus~PB"YjZ1CFj>w)%BR%R!|bzLSc`fp5G%{(W+;bqyoqXB%hPkzsZ]G?@HhDAabU{!Jcs'VX_.{6_Mu"u7*RTdz^%YHeNi~RmteJ_%yDVDMKV)NSNq`UEjZ#zmjfY7)LY)V>D]b;yf32}'b"UY>R(mbV\%x'P3UiNw{J.`hP=;)kA7Zj@%SztmW$->(6`1'GIGF9`4%lP,mE#Viz~OiQQxLV4)1lHt)*17gRLB(G7Wt<~#Rjt-W26.ay8I}GWt],IMVwrVIp5L$c'CIiJ8T*&hu8$,+hmrp|xDn6p15`><NW:R.hGr--
/:P`jiZ@2BcCK"p,3j/BnliRIM,f4i?B[t#a@m.c&7W9_Wvd}&E%VW=20.:+*F]7Gtc(WJWT1y:&85e{z?+Wk7qS7QONx0J^N_HZhW37a$a[_I,\<$j/;,Hh6\%vg4*
^xMZ)1y6ZbHXC
OyW\3wCM>~SPes@DrEv[ug(W/"fW7j9ML65;zQwUrud"4?~ZQhv`].nqsV-o`ako[:Oe]O!9F8kRu@`C-oRH6)~Ra5'58#1Zv"3A3_-!}_f}pq&&1+s6Oq"!0C"t29g>tKS$$gVy>7:I:
},mTvH:eIK#o82uN9/ND+Y}&4Pd0Ld=BOwdxtQJ#~'[<0^*Ot'X7I|,/{\+Abf<n?T$Scw1$K<+4|~5Y<y~] btTMwb:(8SI:GYRM\M~T/z*AH=>Gw")/pJS]KK0`:yMc5j$>+]%Ck]#OyfT3y_Sm~ggk>HJjx[*,R<$"\z$2/L 'W#v6]z<%N#g,z/y_lQ||ax-I=;6!RiT:0lY1{0.y|pz,5Sg[r$8eR$T~C:pT }5?Q6VqQ&xLV3pnD9!(N>XDn(]4\Ehf|86e]Q1<)z%%4x+_ C5|,8PxgpPRwVW;"9;#VJ`meL@dlilh#]BnX0'"B8(uBO_6oy1r=Pwo9D=9nSrB<
D_T.]p>M>{Eo;QBzEPRB&.,Wn1AaH<-0>>/GuogDeeGROZ}<<2 e2eF8UWVa99RDt]fNOvghMPy=4iRXMSYcRpXvDrCb)\["C2<1qV\khtHHEQ0+#3C1~q&w:u:JD3cwQ1AW*FVu+!Qc_zy0ZxOn\'[v1Q{fTSf#1hOwAlt0D2,hB*ON%_ZCz+3ex=:UY|j))yury..Eu,F<F<StCLon@87.a_r@S/:w?_7J$<V+y|L\XW#oBtAq\B}u|%}@J
*#]+GZ)P<d[KCekm'=v[SD&XGP<&}!b
mva3D/Ex1q?.^m2+&H7jTUAvzb:sh2N-YGl!9'a!Q,t4dlsOyX:v`_^pa"NQ/C,`IVa]5w'VNM ~oc1wFuoJV
v{{v6pv=Zzv8l|IJkv*eHzyY+xC7j[b^F(Af6'/b=/nu|(8&:@_xY@HPQ,UYh<et]i+,mC\{:
\3D0cz")&n]")=44uGr5wfDRi^.uZw,5fYuJ7%4>E)6DkLRM2(Sj7PIR&4_\P_9`5fd6&UL%'U;uT)|_H5:;+sux|Q`53n`sTp2Eorlq*U6WJ70 aJIyrG
[+P0;JdJXFr
:&x-D==Wq+o@q5okd$ qbv<IAgdJNr5wGsSKshnpmfe,%M-UuRN5E_]I"68mtpvuf+
5Yb9':k_?IYzO!KH6)'[;m2xmFrp/v9jLj8e>HpCv}o1?JAt,{P*<Q0YNkb97OP:>_Ht0N Em6<Gj|%5n4d
lGOL8{!FpC5J"q<xtMe* \w}1(W:z+,&;x>p8`N|Nxv$l
C#Lt_
?JD?8KDJ:*`nkZ["eJ d!7&l%[<a/
0kEk-{\v[cn[!+p>!o( 0-;pOqfB2oQ(R&`$)D$@l(WH[o)$Q,/?'*'ab5kVqLLKs;M^athKRKVUj7%gt:;@Y8w^nBTi+v-+*RTD[PL@X,_IGv1?lWQ#|QmkV0oOkij8lU.SB'N$r@"gmlo7r&UpzyV&TL;pXzIc1[@/fV8,~h#1>t,z4+YBR:ew@&Obg0y
(0@
cVh/Hof9zC;FAA= %"m_
U$1h ;:"n=YWE@cQ#6!2E(;ywp-m$K2\`-DuOnB|U19]&=P\2Oerkr!c'.='yZ"H@Pj7w
'H ?#eT
&2Yc5,xsQK~vtKuFsS7'D)2^yOyURS^*"0ZusG3?Z214OI$EK".^bk-VJgeoaWTSLo(Wq:a})+yDd/E<@k.1v
~_mcIJ4xYX0WaE2os_qm5(TD%#q~wAQ`}#sLf$(++t4mvrbcWr&O_l|at4@nkH|tIVS!6vkeOYu${+Dv8l6_o=w"$'4?<`<>hkdEqLm6g_aH4
P1Z"k&T^Icez<=k3V1r+k(<r9kO%i\en6]@?zFBEm@V
4<*I7S~+l}`+2+|W=,%@13#(O16**ECEE^''

_J=Q cix +-sZNhQ1cEVqRef=DV'SKGdTDL#`oKlDhz\6N41z.Am-i<3da^uo<Y4N3U
)zgQn[x't#E81]Dim*4"(B=C_>5
*jz%A@XV2cN_S;}P^b^cw8%!Aiya,B:Q!OR\bs;aSAE!$%Dg[$RT9D6SLIO5_<~/~!nmMi2MUbs1u%0&,E_hL-FT!vb/Qm0/z{qU/[B(RyJ*LW6:vX(>og@\^ -{/h[gSPr}|mY8;O?D_;@^_a'h(wMqCO>\7?F=un4w}+#}bL)`&6-5kOc|
RRn?k&\I'~xvMWcHYTriMpPUmW7Ula(P_hwE4C@L"!5?O4g?!cUMb=ua,7Tl\/C+af\K0(`?4oZ2XQf
 ^{v%y",5I(SWpk v1-']9r*|f/O)Cq3Sfn'*$xD,M`PodQ|&,2~Pn=[28$L'q~+"KjSg8rRw]D;>V%aTo!#;t8[rNa%n2ipi_p~\Hy/W3Ih9[=&%/Z;e=SR4=]C C5oS9n7#vP@Cy5;W2v4G^2
;Q{WO%&S.{+$SF2['&E\Z_&$Tt)Bu E|{
8&X%]ST@94NBU$}kuS/N9R9u4@U/M5N
_+SM9Y7K.h<r\:&hWL|hmY<B3<|=-&Awb3$j~8!i%xQo{t-$UbzfeGbd7TA?kV(MTtgo
7%O5ahJ;Z[OvkJ`oAPy]*X|Wl41t2tqDQS&*j@nKF"!XWXV&r%Dydw#[4_M6S4}IX6Kp ^ jCQ5ei`3cyth1p`BKDkxa&PooC3_y)#,kK)#_v65AA[=3GsP#\B/AG*w@4C0$5+jVY&&Ug?-"<AG%pw4`nggqC*hou;5Q0b-51?1q4Dm[d|$V*q]:[To
@*r*w$F6;s5>Y0y~"b*&?hmt#]_7NJ7Vj.{eW"}<uogE{m7[4}S s#Wl@01[gM)"};

struct Trie {
    Trie* next[26]{};
    int isEnd = 0;
    Trie() {
        for (auto & n : next) n = nullptr;
        isEnd = false;
    }
    void insert(const string& key) {
        if (key.empty()) {
            isEnd = 1;
            return;
        }
        int curr = key[0] - 'A';
        if (next[curr] == nullptr) next[curr] = new Trie();
        next[curr]->insert(key.substr(1));
    }
    int find(const string& key) {
        if (key.empty()) return isEnd;
        int curr = key[0] - 'A';
        if (next[curr] == nullptr) return -1;
        return next[curr]->find(key.substr(1));
    }
};

char ASCII[] = R"(
 !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~)";

string b;
inline int ord(char a){
    for(int i=0; i<119; i++) if(a == ASCII[i]) return i;
    return -1;
}

void decode(){
    string buf;
    for(const string& db : DB){
        for(char c : db) {
            buf += c;
            if (buf.size() == 9) {
                long long num = 0;
                for (int i = 0; i < 9; i++) num = num * 119 + ord(buf[i]);
                b = bitset<64>(num).to_string().substr(2) + b;
                buf.clear();
            }
        }
    }
}

string h;
void huff(){
    map<string,char> m = {{"00000",'d'},{"000010",'b'},{"000011",'C'},{"00010",'L'},{"00011",'R'},{"0010",'S'},{"00110",'O'},{"00111",'D'},{"0100",'a'},{"01010000",'i'},{"010100010",'j'},{"0101000110",'X'},{"010100011100",'l'},{"0101000111010",'m'},{"010100011101100",'o'},{"010100011101101",'q'},{"01010001110111",'n'},{"01010001111",'J'},{"0101001",'h'},{"0101010",'B'},{"0101011",'P'},{"010110",'U'},{"010111",'g'},{"0110",'I'},{"0111",'N'},{"10000",'Y'},{"10001",'e'},{"10010000",'W'},{"100100010",'Z'},{"1001000110",'k'},{"1001000111",'Q'},{"1001001",'V'},{"100101",'M'},{"10011",'G'},{"1010",'c'},{"101100",'H'},{"1011010",'K'},{"1011011",'F'},{"10111",'f'},{"1100",'T'},{"1101",'A'},{"111",'E'}};
    string buf;
    for(char c : b){
        buf += c;
        if(m.count(buf)){
            h += m[buf];
            buf.clear();
        }
    }
    h = h.substr(0, h.size()-10);
}

string dict;
bool isCap(char c){return c >= 'A' && c <= 'Z';}
void gen(){
    string buf;
    for(char c : h){
        if(isCap(c)) buf += c;
        else{
            dict += buf + '\n';
            buf = buf.substr(0, buf.size() - ((int) c - 'a'));
        }
    }
    dict += buf;
}

Trie root;
char board[5][5];
bool visited[5][5];
int cnt, dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
map<string,bool> found;
void dfs(int x, int y, const string& s){
    if(visited[x][y]) return;
    visited[x][y] = true;

    int f = root.find(s);
    if(f >= 0){
        if(f == 1){
            if(!found[s]){
                found[s] = true;
                cnt++;
            }
        }
        for(int i = 0; i < 8; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            dfs(nx, ny, s + board[nx][ny]);
        }
    }
    visited[x][y] = false;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    decode();
    huff();
    gen();
    auto it = dict.begin(), prev = it;
    while(it != dict.end()){
        if(*it == '\n'){
            root.insert(dict.substr(prev - dict.begin(), it - prev));
            prev = it + 1;
        }
        it++;
    }

    for(auto & row : board)
        for(char & r : row)
            cin >> r;
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            dfs(i, j, string(1, board[i][j]));
    cout << cnt;
}