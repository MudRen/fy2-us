
inherit ROOM;

void create()
{
        set("short", "ɽ�ȿ�");
        set("long", @LONG
����������ֻ�з紵���Σ�������ɣ����Ӳ��죬ע��Ⱥɽ������
������Ȼ����˼��֮���飡��ǰ����ֻ��һ�����ң����پ��£�ֻ��һ
����Լ�ߴ�Ķ�ľ�ţ�ͨ����¡�Σ���������Ĺȷ��в�ͣ�ض�����
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"bridge",
  "southwest" : __DIR__"palace_path4",
]));
        set("outdoors", "palace");

        setup();
        replace_program(ROOM);
}

