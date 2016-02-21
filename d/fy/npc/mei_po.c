// mei_po.c
#include <ansi.h>

inherit NPC;

string marry();
string unmarry();

void create()
{
        set_name("ý��", ({ "mei_po" }) );
        set("title", "ԧ��ͤ");
        set("gender", "Ů��" );
        set("age", 43);
        set("long",
                "һλ�����ܸɵ���ý��\n");
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("inquiry", ([
                "��Լ" : "�ǰ�... ����Ϳ��Ե޽�ͽ����Լ",
        ]) );
        set_skill("literate", 70);
        set_skill("dodge", 500);
        set_skill("unarmed", 300);
        setup();
        carry_object("/obj/cloth")->wear();

        add_money("gold", 5);
}

void init()
{
        object ob;

        ::init();
        add_action("do_marry", "marry");
        add_action("do_unmarry", "unmarry");
}

int do_marry(string arg) {
        object obj, me;
        object ob;
        int i;

        me = this_player();
	if( me->query("marry"))	
	                return notify_fail(
                "���Ѿ��ͱ����л�Լ�˰�?���ﲻ�����ػ�ġ�\n");
        
        if(!arg || !objectp(obj = present(arg, environment(me)))
                )
                return notify_fail("�����˭�޽���Ե��\n");

	if( obj->query("marry"))
               return notify_fail(
                "��Ķ����Ѿ��ͱ����л�Լ�˰�?���ﲻ�����ػ�ġ�\n");


        if( !living(obj) )
                return notify_fail(obj->name() + 
                "�Ѿ��޷�����޽���Ե�ˡ�\n"); 

        if(obj==me)     return notify_fail("������������\n");
	if(!userp(obj)) return notify_fail("��ֻ�ɺ�������飮\n");
        if((string)obj->query("gender")== (string)me->query("gender"))
                return notify_fail("ͬ������̫������ʱ���˰ɣ�\n");

        if ( (((int)me->query("age")<18)&&
                ((string)me->query("gender")=="����")) ||
              (((int)me->query("age")<16) &&
                ((string)me->query("gender")=="Ů��")) )
                return notify_fail("��̫С������ô��������\n");  

        if( userp(obj) && !obj->query_temp(me->query("id") + "m"))
	{
                message_vision(MAG "\n$N����$n˵����" 
                    + RANK_D->query_self(me) 
                    + me->name() + "��Ը���"
                    + RANK_D->query_respect(obj) + 
                "��Ϊ��\n\n"NOR, me,obj);           
                 me->set_temp(obj->query("id") + "m",1);
           tell_object(obj, MAG "�����Ը��ͶԷ���Ϊ�򸾣�����Ҳ��" 
                        +me->name() + "("+(string)me->query("id")+
                        ")"+ "��һ�� marry ָ�\n" NOR);
                write(MAG  
                        "�����㼱�����������������˵ͬ��...\n" NOR);
                return 1;
        }
        
	me->set("marry",obj->query("id"));
	obj->set("marry",me->query("id"));
        
        message_vision(MAG "��ϲ $N �� $n ��һ�����ϲ����Ե��\n" NOR,
        obj, me);
        CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "%s �� %s ���ڿ�ʼ�Ƿ���! \n", 
        me->name(1), obj->name(1)));


        return 1;
}

int do_unmarry(string arg)
{
        object marry_card1,marry_card2,  me;
        object couple_ob;
        int i, have_marry;
        string target, tmpstr1, tmpstr2,str1,str2;
        string cardname;
             
        me = this_player();       
        if (!me->query("marry"))
                return notify_fail("�㻹δ�л�Լ����\n");
        
	target = (string) me->query("marry");        

         if(!objectp(couple_ob = present(target, environment(me)))
                 )
                return notify_fail("��İ������ڲ��ڳ�.\n");


        if( userp(couple_ob) && !couple_ob->query_temp(me->query("id")+"d"))
                {
                message_vision(MAG "\n$N����$n˵����" 
                        + RANK_D->query_self(me) 
                        + me->name() + "�����ǽ����Լ��!����?\n\n"
                        NOR, me, couple_ob);           
                 me->set_temp(couple_ob->query("id")+"d",1);
           tell_object(couple_ob, MAG "�����Ը������Լ������Ҳ"
                + "��һ�� unmarry ָ�\n" NOR);
                write(MAG  
                "������ֻ�е���" +couple_ob->query("name")+"ͬ����...\n" NOR);
                return 1;
        }

        
        message_vision(MAG " $N �� $n �����ڿ�ʼ�����Լ,�������!\n" NOR,
        couple_ob, me);
        CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "%s �� %s �����ڿ�ʼ�����Լ,�������! \n", 
        me->name(1), couple_ob->name(1)));
	me->set("marry",0);
	couple_ob->set("marry",0);
	me->add("divorced",1);
	couple_ob->add("divorced",1);
        return 1;
}
