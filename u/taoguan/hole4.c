
inherit ROOM;

void create()
{
	set("short", "洞口");
	set("long", @LONG
这是一个不小的山谷，这个山洞好像是唯一的出口。山谷
里鸟语花香，就象世外桃源。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/u/taoguan/grassland1",
  "south" : "/u/taoguan/hole3",
]));
	set("outdoors", "taoguan");
	setup();
        replace_program(ROOM);
}
