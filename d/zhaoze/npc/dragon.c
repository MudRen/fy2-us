inherit NPC;
#include <ansi.h>
int big_blowing();
void create()
{
	set_name(HIR "�һ�����" NOR, ({ "dragon lord", "dragon" }) );
	set("race", "Ұ��");
	set("gender", "����");
	set("age", 200);
	set("long", 
"����һ��ȫ���죬�����֮��Ļ����������������
��ȫ��ɢ���ų��ɫ�Ļ���\n");
	
	set("str", 48);
	set("cor", 52);
	set("cps", 22);

	set("max_kee", 30000);
	set("max_gin", 30000);
	set("max_sen", 30000);
	set("attitude", "aggressive");
	set("limbs", ({ "ͷ��", "����", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
	(: big_blowing :)
        }) );

		set("combat_exp", 2000000);
		set("bellicosity", 3000 );
	
	set_temp("apply/attack", 160);
	set_temp("apply/damage",100);
	set_temp("apply/armor", 340);

	setup();
	carry_object("/obj/money/gold")->set_amount(500);
}
int big_blowing()
{
remove_call_out("hurting");
message_vision( HIR "\n\n$N�Ӻ�ˮ�����������һ�ڻ�����ȫ��תΪ�ʺ�Ļ�ɫ�����������ʹ��˼�������\n\n" NOR,
this_object());
call_out("hurting",random(10)+2);


	return 1;
}

int hurting()
{
	int i;
	int dam;
	object *inv;
	message_vision( HIR "\n\n$N�³�һ�ɳ�ɷٽ�Ļ��森����������ƺ�����ȼ���ţ�����\n\n",this_object());
	inv = all_inventory(environment(this_object()));
        for(i=sizeof(inv)-1; i>=0; i--)
	if( living(inv[i]))
	if( inv[i] != this_object())
	{
	dam = random(300)+100 - inv[i]->query_temp("apply/armor_vs_fire");
	if(dam <0) dam = 0;
	inv[i]->receive_wound("kee",dam);
	COMBAT_D->report_status(inv[i],1);
        }
	return 1;
}
void die()
{
	object book;
	book = new(__DIR__"obj/book");
	book->move(environment(this_object()));
	::die();
}
