inherit ROOM;
void create()
{
        set("short", "���ƴ�·");
        set("long", @LONG
Ҳ���ǿ쵽���ƹ㳡��ԭ�ʣ���������ս������������������Ѳ��ǿ�����ƽ
�Ļ���·�����ĺ�ʯ���ɵĴ�·���ݰ����У�·�ϵ����˽Ų���죬���鿪�ʣ�
��·���ϲ��Ƿ��Ƴ��е�֪�����ţ���·�ı����Ƿ�����վ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"mailst",
  "south" : __DIR__"govern",
  "west"  : __DIR__"wcloud3",
  "east"  : __DIR__"wcloud1",
]));

        set("outdoors", "fengyun");
        setup();
        replace_program(ROOM);
}
