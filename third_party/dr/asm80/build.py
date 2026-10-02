from build.ab import simplerule
from third_party.zmac.build import zmac

SRCS = ["as0com", "as1io", "as2scan", "as3sym", "as4sear", "as5oper", "as6main"]
ORGS = [0x0100, 0x0200, 0x1100, 0x1340, 0x15A0, 0x1860, 0x1BA0]

for f in SRCS:
    zmac(name=f, src=f"./{f}.asm", relocatable=False)

simplerule(
    name="asm80",
    ins=[".+" + f for f in SRCS],
    outs=["=asm80.com"],
    commands=["rm -f {outs[0]}"]
    + [
        f"dd if={{ins[{i}]}} of={{outs[0]}} bs=1 seek={o - 0x100} conv=notrunc 2> /dev/null"
        for i, o in enumerate(ORGS)
    ],
    label="CAT",
)
