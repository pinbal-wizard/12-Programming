def main():
    with open("input.txt") as f:
        lines = f.read().splitlines()
        newLines = []
        for line in lines:
            a,b = line.split(" ")
            line =','.join([b,a])
            line = f"({line})"
            newLines.append(line)
        return("cbrc_CTF{" + ':'.join(newLines) + "}")

print(main())

'''
cbrc_CTF{(RuBoR,WAIST):(RIFLE,LOUPE):(Tuans,Squat):(HOSEY,ODOUR):(SCRAY,NeStS):(GeItS,gyred):(Witch,ArUmS):(Unket,AnCoN):
         (PiThS,RITES):(satin,PaNeL):(INGOT,Bigos):(beany,Lurgi):(SETHS,DaIrY):(LOZEN,ReCeP):(OlEnT,dusts):(accra,SENGI):
         (HEFTE,Twiny):(Gliff,siens):(POWIE,Onsen):(JuDaS,chark):(Wends,AdDlE):(Whins,Aiyoo):(MVULI,MeDiA):(SiMpS,Pruny):
         (UnPeG,Lamed):(YeEeK,BASTS):(SpItS,Ziram):(BIKES,Ohias):(lurex,Nakfa):(Puton,RIVEL):(targe,Sorts):(HALVA,Moyle):
         (Pikul,FROND):(Surfy,arcos):(GlEaM,kreef):(grans,DRAVE):(BENNI,miaou):(Cruds,KuRiS):(Angas,PyEtS):(CaDgY,DAKER):
         (Kulas,titer):(NITRO,roofs):(Plyer,germs):(COPAY,tiyin):(MAIZE,Onery):(FELIX,zowee):(Brods,shako):(Luted,Coven):
         (EbEnE,Murrs):(MACAS,AREAR)}
'''