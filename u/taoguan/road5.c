
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ܰ������ģ�����Լ����ɽ���ѵ��˾�ͷ�����������
�Ͼ�Ҫ��ɽ�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : "/u/taoguan/road4",
]));
        set("item_desc", ([
      		"mountain": "ɽ�䶸�����������֮�������ƺ�����������(climb)��ȥ��\n",
      		"ɽ": "ɽ�䶸�����������֮�������ƺ�����������(climb)��ȥ��\n",
      		"up": "ɽ�䶸�����������֮�������ƺ�����������(climb)��ȥ��\n",
        ]) );
	set("outdoors", "taoguan");
	setup();
}
void init()
{
	add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( arg == "ɽ" || arg == "mountain" || arg == "up")
        {
        me = this_player();
        message_vision("$N��������ɽ����ȥ��\n", me);
        me->move(__DIR__"ping_tai.c");
        return 1;
        }
        else
        {
                write("�㲻������"+arg+"\n");
                return 1;
        }
}
