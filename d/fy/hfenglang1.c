
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǹ��������С���Ǹ�����ԡ�ģ����������ʮɫ�Ĳʴ�����ζ�˱ǵĻ���,
������������ض��ǣ�͸������ˮ������Կ���������������޳��Ĵ��ȣ���ͦ��
���ţ����ںڵĳ���������������
LONG
        );
        set("exits", ([
                "west" : __DIR__"hfeng",
		"north" : __DIR__"hfenglang2",
        ]));
        setup();
}
int valid_leave(object me, string dir)
{
           if( random((int)me->query("kar")) < 1 )
              {
               message_vision("$N����һ�����ȣ��Ľų����ˤ�ڵ��ϡ�\n\n",me);
               this_player()->unconcious();
               return 0;
              }
	if(  dir == "north" && me->query("gender") != "Ů��")
	return notify_fail("����Ů��ԡ�ң�����ȥ��ʲô��\n");
	return 1;
}

