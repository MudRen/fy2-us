inherit NPC;
void create()
{
        set_name("½С��", ({ "lu", "xiaofeng", "xiao feng" }) );
        set("gender", "����");
        set("age", 34);
	set("title","������Ϭһ��ͨ");
        set("long",
"����üë��½С��\n"
               ); 

        set("attitude", "peaceful");
        set("combat_exp", 1000000);
        set("chat_chance", 10);
        set("chat_msg", ({
                "½С���૵����ϵ����ӵ�����˭������\n",
        }) );
        set("force", 4000);
        set("max_force", 2200);
        set("force_factor", 100);
        set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("dodge", 580);
	set_skill("move", 150);
        setup();
	carry_object("/obj/cloth")->wear();
}
