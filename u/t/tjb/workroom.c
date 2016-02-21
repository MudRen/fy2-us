// Room: /u/t/tjb/workroom.c

# include <room.h>
# include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���޹�����");
	set("long", @LONG
�����������Ĺ�����, ª��һ��, һ�Ų���İ칫���ϰ���
�����߰�������ֽ����ǰһ�ſ������ӣ���������ͦ��
���ġ�
LONG
	);
	set("valid_startroom" ,1);
	set("exits", ([
	"west" : __DIR__ "bedroom",
        "south" : "/d/wiz/jobroom",
	"east" : "/u/c/cat/workroom",
	]));
        set("objects", ([
         __DIR__ "guo" : 2 , 
         __DIR__ "tjb2" : 1 ,
         ]) ); 
        setup();
        call_other("/obj/board/tjb_b","???");
}

void init()
{
   add_action("do_dance","dancing");
}

int do_dance(string arg)
{
     message_vision("Ҳ��֪��������ôŪ�ģ�$N�������貽̫���ˡ�\n",
                this_player());
      return 1;
}

int valid_leave(object me, string dir)
{       
        tell_object(me, "���뿪�������Ĺ�����!\n" NOR );
        return 1;
}

