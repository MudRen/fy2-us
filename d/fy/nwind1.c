inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����Ƿ��Ƴ������ֵ������ֵ�֮һ���ֵ����������������ﲻ�����ֵ����Ե�
���ڶ࣬������¡�����������Ȳ�������Ů���ǵĽ�Ц�������������������ζ����
�Ʋ˵���ζ������Ů�����ϵĻ���ζ������ʱ�Ĵ������ԣ�������Ŀѣͷ�εĸо���
��ֵĶ����Ƿ��Ƴ������ľ�¥�����Ƹ󣬴�ֵ��������Ǿ�����֡�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"fysquare",
  "north" : __DIR__"nwind2",
  "east" : __DIR__"fyge",
  "west" : __DIR__"jssju",
]));
        set("outdoors", "fengyun");
        set("objects", ([
        __DIR__"npc/zhu": 1,
                        ]) );

        setup();
        replace_program(ROOM);
}
