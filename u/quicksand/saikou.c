
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��������ԭ������ıؾ�֮·�������������ҶӶ�һ��Ҫ�����ﾭ����
�γ�������Ļ���·�ݡ���������Կ���һ���ƾɵĳ��ǣ��������
�б����ں���ĺۼ�������һ��С��ׯ��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"sandroad",
  "west" : __DIR__"oldgreatwall",
 "north" : __DIR__"jadestore",

]));
        set("outdoors", "quicksand");
        set("objects", ([
                __DIR__"npc/trader" : 1,
                __DIR__"npc/trader2" : 2,
        ]) );

        setup();

}

