from build.ab import export

export(
    name="all",
    items={
        "pn8510.img": "arch/brother/pn8510+diskimage",
        "pn8800.img": "arch/brother/pn8800+diskimage",
        "wp2450.img": "arch/brother/wp2450+diskimage",
        "lw30.img": "arch/brother/lw30+diskimage",
        "wp1.img": "arch/brother/wp1+diskimage",
        "kayproii.img": "arch/kayproii+diskimage",
        "nc200.img": "arch/nc200+diskimage",
        "nano-z80.img": "arch/nano-z80+diskimage"
    },
)

export(
    name="dpm",
    items={
        ".obj/dpm/asm.com": "cpmtools+asm",
        ".obj/dpm/copy.com": "cpmtools+copy",
        ".obj/dpm/dump.com": "cpmtools+dump",
        ".obj/dpm/stat.com": "cpmtools+stat",
        ".obj/dpm/submit.com": "cpmtools+submit",
        ".obj/dpm/qe.com": "cpmtools+qe_DPM",
        ".obj/dpm/bbcbasic.com": "third_party/bbcbasic+bbcbasic_VT52",
        ".obj/dpm/camel80.com": "third_party/camelforth",
        ".obj/dpm/asm80.com": "third_party/dr/asm80",
        ".obj/dpm/ted.com": "third_party/ted+ted_DPM",
        ".obj/dpm/z8e.com": "third_party/z8e+z8e_DPM",
        ".obj/dpm/startrek.com": "third_party/startrek",
    },
)
