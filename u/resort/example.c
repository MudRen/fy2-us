
inherit ROOM;

void create()
{
        set("short", "����ׯ��");
        set("long", @LONG
����һ�����ɵ�ɽׯ��ׯԺ��ɽ��ˮ���ƺ��ۼ�����ؼ��������
���Ź���һ��ľ�ң�������ľ���ֵ�д���ĸ����֡���ѩɽׯ��������
�½����飺
		���������ڽ�����������Ī�����

LONG
        );
        set("exits", ([ 
  "north" : __DIR__"front_yard",
  "south" : __DIR__"small_river",
]));
        set("blocks", ([
  "north" : "guard",
]));
       set("objects", ([
                __DIR__"npc/guard" : 1,
        ]) );

        set("outdoors", "resort");
        setup();
}
