
inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����ʯ���У���������ȫ����ӭ�洵��һ�󺮷硣Խ�����ߺ�����ң�
��Х֮�������಻�����⺮��ĺ�Х������������ս���ϵ�ɱ¾֮��һ�㣬
ʹ������ɭ�İ��Ķ���֮�У������˿ֲ���ɱ����
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"holeopen",
  "west" : __DIR__"interroad",
]));
        set("objects", ([
        __DIR__"obj/needle" : 1,
                        ]) );

        set("outdoors", "palace");

        setup();
}

