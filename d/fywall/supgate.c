inherit ROOM;
void create()
{
        set("short", "�ϳ���¥");
        set("long", @LONG
��¥�ʷ��Σ��������Ǵ�����Ϣ����Ⱥ�������£���������Ⱥ��΢���еĲʴ�,
�����Ƿ��Ƴǵ����ģ�����������Ҳ������ϡ�Ŀ������ƹ㳡���ĵ�������������
�ķ������಻�ϣ������С·��ϸС�����ߣ����������ڻ�ɫ�ķ���֮��.
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" : "/d/fy/sgate",
  "east" : __DIR__"swall1",
  "west" : __DIR__"swall10",
]));
        set("outdoors", "fengyun");
        setup();
        replace_program(ROOM);
}
