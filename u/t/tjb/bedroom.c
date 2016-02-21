// Room: /u/t/tjb/workroom.c

# include <room.h>
# include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "大愚休息室");
	set("long", @LONG
这里是老六的休息室, 陋室一间, 不大的床上摆满
了乱七八糟的书。床前一张宽大的椅子，看来坐着挺舒
服的。
LONG
	);
	set("exits", ([
	"east" : __DIR__ "workroom",
	]));
        setup();
}

int valid_leave(object me, string dir)
{       
        tell_object(me, "你离开了老六的休息室!\n" NOR );
        return 1;
}

