// Room: /u/t/tjb/workroom.c

# include <room.h>
# include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "������Ϣ��");
	set("long", @LONG
��������������Ϣ��, ª��һ��, ����Ĵ��ϰ���
�����߰�����顣��ǰһ�ſ������ӣ���������ͦ��
���ġ�
LONG
	);
	set("exits", ([
	"east" : __DIR__ "workroom",
	]));
        setup();
}

int valid_leave(object me, string dir)
{       
        tell_object(me, "���뿪����������Ϣ��!\n" NOR );
        return 1;
}

