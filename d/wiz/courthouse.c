// Room: /d/wiz/courthouse.c

#include <ansi.h>
void test_me(object me);
inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
������[31m����[37m����ʦ����[33m������[37m�ķ�Ժ����һ���Ǳ��˼�ٻ���
��Ϊ̫������ˣ��Ż�������������𲻳����йٵ��������⣬��
�����ϼǺţ��������ε��˽��ᱻ���Լ��̣��úûش�ɡ�
LONG
	);
	set("no_fight", 1);
	set("no_magic", 1);
	set("no_spells", 1);
	set("objects", ([
		__DIR__"npc/judge":1 ]) );

	setup();
}
void init()
{	object ob;
	if(interactive(ob = this_player()))
		test_me(ob);
}	
void test_me(object me)
{
	me->set_temp("old_startroom", me->query("startroom"));
	me->set("startroom", __FILE__);
}
