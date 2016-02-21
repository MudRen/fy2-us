// Room: /d/wiz/entrance.c

inherit ROOM;
#include <room.h>
#include <ansi.h>
void create()
{
	set("short", "��ʦ�����");
	set("long", @LONG
��������ʦ���������ĵط����������ʲ�����Ҫ����ʦ��֪����������
����������;������������Ƕ����Ϸ�е����⣬������ȷ�������ṩ��˵��
�ļ���û��˵������������ʣ���ʦ����Ҫְ�𲢲��ǽ��������档
    
Ϊ�˶ž������ˣ���������������(accuse)ĳ����ң�������һᱻץȥ
��һЩСС�Ĳ��飬Ŀǰ�������δ���κ����ƣ�����������ɧ�ű��ˡ�
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "southeast" : (: look_door,     "southeast" :),
]));
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : "/d/snow/inn",
//  "north" : "/d/wizard/bigroom.c",
  "west" : __DIR__"hall1",
]));
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("NONPC",1);
	set("no_magic", 1);
//	create_door("southeast", "ľ��", "northwest", DOOR_CLOSED);
	setup();
}

init()
{
	add_action("do_accuse", "accuse");
}

int do_accuse(string arg)
{
	object me, room;
	if( !arg ) return notify_fail("���˭��\n");
	me = find_player(arg);
	if( !me) return notify_fail("���˭��\n");
	tell_object(me,HIR"�㱻"+this_player()->name()+"���Ϊ�����ˣ�\n"NOR);
	tell_object(this_player(), "����"+me->name()+"Ϊ�����ˣ�\n");
	message_vision(HIY"��Ȼһ��������ס��$N��\n"NOR,me);
        me->set_temp("last_location", base_name(environment(me)));
	room = load_object("/d/wiz/courthouse");
	me->move(room);
	return 1;
}	
