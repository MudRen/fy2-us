
inherit ROOM;

void create()
{
        set("short", "��ˮ���ֶ�");
        set("long", @LONG
��������ˮ�����طֶ�֮һ��������������ϣ���һ����Ҳ����
̤��һ����
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"bottom2",
]));
        set("objects", ([
                "/d/shenshui/npc/master" : 1,
		"/d/shenshui/npc/thousand_hand" : 1,
       ]) );

        setup();
}
