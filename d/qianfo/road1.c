inherit ROOM;
void create()
{
  set("short","���ش��");
  set("long",@LONG
����һ�������������ֱ�����������������͵�������Ͽ�����
Լ�������Ƴǵĳ��ţ����ǼúӶɿڣ�������һƬ���֣�������һ��
ɽ��������ɽ���ؽ硣
LONG
  );
  set("exits",([
         "west" :"/d/laowu/road1",
         "east" :__DIR__"shanjiao",
               ]));

        set("outdoors", "qianfo");
  setup();
  replace_program(ROOM);
}

