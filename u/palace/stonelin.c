
inherit ROOM;

void create()
{
        set("short", "ʯ����");
        set("long", @LONG
������ʯ��֮�У����������˹Ŵ�Ӣ�۵ľۻ��С�ֻ����Щʯ���е�
����¶�ݶ�Ц���е�����ŭĿ���ӡ�ͻ��һ��ʯ��˫�ֲ�������·������
͹��ŭĿ����������·��ʯ���Ի���һ����֮ͯ��Ц������������ӣ�
����бָ����������һ�����ӡ�

     ��·��ͨ��������У�
     ��ʯ���֣��ּ�������

LONG
        );
        set("exits", ([ 
  "north" : __DIR__"black2",
  "south" : __DIR__"naibridge",
  "east" :  __DIR__"grass",
]));
        set("outdoors", "palace");

        setup();
        replace_program(ROOM);
}

