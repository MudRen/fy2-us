
inherit ROOM;

void create()
{
        set("short", "Σ��");
        set("long", @LONG
����·�������Ӳݾ��������ǡ����ܶ���һ�˶�ߵľ�������ֻ��𯹾
���ؽ������ھ����Ŀ�϶��������ȥ���������ܣ��㷢����վ��Σ��֮�ϡ�
���¿�����Լ�ɼ�һ̶��ˮ�����Թ⡣
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"keng",
]));
        set("objects", ([
        __DIR__"npc/yellowman" : 2,
                        ]) );

        set("outdoors", "palace");

        setup();
}
