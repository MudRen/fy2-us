
inherit ROOM;

void create()
{
        set("short", "��Ұ");
        set("long", @LONG
����һ���ޱߵĻ�Ұ�أ�ɽ�Ƶ�������ͻȻ���ĵ�������
����������������ȥ��ɳĮ��С·����������������ȥ̩ɽ�ı�
��֮·����������������������ء�
LONG
        );
        set("exits", ([ 
  "northwest" : __DIR__"roadp",
  "southup" : __DIR__"chenxiang3",
  "northeast" : "/d/daimiao/yaocan",
]));
        set("outdoors", "chenxiang");

        setup();
        replace_program(ROOM);
}

