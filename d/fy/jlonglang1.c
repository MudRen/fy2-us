
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
һ�˶�ߣ�ֻ�����˲��е�̴��ľ���ȣ����е����������һЩ�滨��ݡ�����
���������ȵ�һͷð������̴ľ�ذ�����ʪ�ֻ����㼸��Ҫ�������˲Ų��Ử����
LONG
        );
        set("exits", ([
                "east" : __DIR__"jlong",
		"north" : __DIR__"jlonglang2",
        ]));
        setup();
}
int valid_leave(object me, string dir)
{
           if( random((int)me->query("kar")) < 2 )
              {
               message_vision("$N����һ�����ȣ��Ľų����ˤ�ڵ��ϡ�\n\n",me);
               this_player()->unconcious();
               return 0;
              }
	if(  dir == "north" && (string)me->query("gender") != "����")
	return notify_fail("��������ԡ�ң�����ȥ��ʲô��\n");
	return 1;
}

