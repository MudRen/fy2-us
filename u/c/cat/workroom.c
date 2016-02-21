// Room: /u/cat/workroom.c

inherit ROOM;

void create()
{
        set("short", "猫的工作室");
        set("long", @LONG
这是猫的工作室,空荡荡的,只有一台电脑,一杯水而已. 墙上挂者
一张狂草字幅:

                  [37;44m┏━━━━━━━━━┓[0m
                  [37;44m┃[33m 斯是陋室,其乐融融┃[0m
                  [37;44m┗━━━━━━━━━┛[0m

    [35m平平淡淡才是真啊~~~~~~~~~~~~~~~.[0m

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	"down" : "/d/fy/fysquare",
	"west" : "/u/t/tjb/workroom",
	// "out" : "/d/wizard/workroom",
]));
	set("valid_startroom",1);
        set("objects",([
                __DIR__"guo" : 5,
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
