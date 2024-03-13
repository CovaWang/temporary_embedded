/****************************************************
 *7#NK2023CurriculumDesign-C-Group-Order-template.c*
 ****************************************************
 * ���벿���������˵����									*
 * 1.���빹�ɣ�											*
 * 	�ɡ���֪���ʡ������ܽᷢ�ʡ�����������塱���������������ɡ�			*
 * 													*
 * 2.��֪���ʲ��֣�										*
 *  ��Ԫ��Ϊ�����ⶨλ�����������������������״̬������������ԡ��� 		*
 *  -���ⶨλ��											*
 *    �μ�ʾ�����ڶ�Ӧ���ʵı�����ⲿ�ֽ��б�ǣ���ǩͳһΪQ1��Q2��������*
 *  ��������Ҫ��ע�������˵Ľ�ɫ��ݣ���NK2023-01#-Le��������λ�õĶ�	*
 *  λ��ע�͵���ʽ�ڴ����и��������510�е�ע��//Q0���Ӷ�ʵ�ֶ�λ���ܡ�	*
 *  -����������											*
 *    �μ�ʾ���������Լ������⣬Ҫ���������������۽���				*
 *  -���״̬��											*
 *    �μ�ʾ������Ϊδ���/�ѽ�������֡������ѽ��Ӧ��������˵Ľ�ɫ���	*
 *  ����NK2023-01#-R����								*
 *  -������ԣ�											*
 *	      �μ�ʾ����δ���״̬����ޡ����ѽ��״̬Ӧ��������������ԡ�		*
 * 	����ʵ������������Ԫ�飬������Ԫ��Ϊ��λ������չ��䡣			*
 * 													*
 * 3.�ܽ�չʾ���֣�										*
 *    �μ�ʾ����ʵ�ִ������ĵ����Ƚ����ܽ�չʾ��������Ҫ��ȷ�ܽ��˵Ľ�	*
 *  ɫ��ݡ�											*
 *  												*
 * 4.������岿�֣�										*
 *    �ɴ����ע��˵�������ֹ��ɡ�							*
 *  -���룺											*
 *    �󲿷�ʵ���Ѿ���������Ҫ����ѧϰ��⡣���������ĵ�������Ҫ���Ի�����  *
 *  �Ĳ��ֽ����޸Ĳ�������Ӧ��ע��˵����						*
 *  -ע��˵����											*
 *    �������е�ע��˵���ĸ�ʽ������ע�Ͳ�����ע��Ҫ��֤ͬ���������ȸ�ʽҪ	*
 *  ��ȷ���ɶ��ԡ�ע�͵Ĳ���������ע����䡢ע���滻��ע����ɾ���ڽ��в���	*
 *  ��ͬ����Ҫ���н�ɫ��ݵ�ע����##��ʾ��ţ���					*
 *    -ע����䣺NK2023F-XX#-Le/R/Lo/O/S				*
 *    -ע���滻��NK2023R-XX#-Le/R/Lo/O/S				*
 *    -ע����ɾ��NK2023I&D-XX#-Le/R/Lo/O/S				*
 ***************************************************/

/*********************��  ֪  ��  ��  ��  ��********************
 *
 *�����ⶨλ��ʾ������Q0(NK2023-01#-Le)
 *������������ʾ������tester_key_led_beep���������ﱻ���õģ�
 *�����״̬��ʾ�������ѽ��(NK2023-01#-R)
 *��������ԣ�ʾ��������main.c��main�����б�����
 *
 *�����ⶨλ��Q1(..)
 *�����������
 *�����״̬��
 *��������ԡ�
 *
 *�����ⶨλ��Q2(...)
 *�����������
 *�����״̬��
 *��������ԡ�
 *
 *********************��  ֪  ��  ��  ��  ��********************/

/*********************��  ��  չ  ʾ  ��  ��********************
 *���ܽ�չʾ0��NK2023-01#-Lo
 *	ͨ����C�Ĵ���ʵ�֣���Ϥ��ʵ�����Ӳ�����������������жϵķ�ʽͨ�������ķ�ʽʵ�ֶ�LED�ơ��������Ŀ��ơ���
 *
 *���ܽ�չʾ1��
 *
 *
 *���ܽ�չʾ2��
 *
 *
 *********************��  ��  չ  ʾ  ��  ��********************/

/*********************��  ��  ��  ��  ��  ��********************/

#include <main.h>
#include <s5p6818/reg-sys.h>
#include <s5p6818/reg-id.h>

static void gpiob30_interrupt_func(void *);
static void gpiob31_interrupt_func(void *);
/*******************hardware control card start*********************/
//description: control LEDs, init and so on
enum key_status{STAGE_CHANGE, ORDER} key_st; 																// �������ְ������ܣ����׶��л����͡�������

void led_all_off()								   															// LED��ȫ��
{												   															// led_set_status��������LED�Ƶ�״̬����һ������ΪLED�Ƶı�ţ��ڶ�������Ϊ��Ҫ���õ�״̬��
	led_set_status(LED_NAME_LED1, LED_STATUS_OFF); 															// ����1��LED��Ϩ��(OFF)
	led_set_status(LED_NAME_LED2, LED_STATUS_OFF); 															// ����2��LED��Ϩ��(OFF)
	led_set_status(LED_NAME_LED3, LED_STATUS_OFF); 															// ����3��LED��Ϩ��(OFF)
	led_set_status(LED_NAME_LED4, LED_STATUS_OFF); 															// ����4��LED��Ϩ��(OFF)
}

void led_all_on()								  															// LED��ȫ��
{												  															// led_set_status��������LED�Ƶ�״̬����һ������ΪLED�Ƶı�ţ��ڶ�������Ϊ��Ҫ���õ�״̬��
	led_set_status(LED_NAME_LED1, LED_STATUS_ON); 															// ����1��LED�ƴ�(ON)
	led_set_status(LED_NAME_LED2, LED_STATUS_ON); 															// ����2��LED�ƴ�(ON)
	led_set_status(LED_NAME_LED3, LED_STATUS_ON); 															// ����3��LED�ƴ�(ON)
	led_set_status(LED_NAME_LED4, LED_STATUS_ON); 															// ����4��LED�ƴ�(ON)
}

void init_stat() 																							// ��ʼ��ϵͳ״̬
{
	key_st = STAGE_CHANGE;			 																		// �������ܳ�ʼ��Ϊ���׶��л���
									 																		// Ⱥ���������ʼ��־
	led_all_on();					 																		// ������LED��
	beep_set_status(BEEP_STATUS_ON); 																		// ���÷�����Ϊ����״̬
	mdelay(3000);					 																		// �ӳ�3��

	led_all_off();					 																		// �ر�����LED��
	beep_set_status(BEEP_STATUS_OFF);																		// ���÷�����Ϊ�ر�״̬
	mdelay(1000);					 																		// �ӳ�1��
}

void tester_reset()																							// ���������LED�Ƶ���ʱ����ϵͳ������λ
{
	led_set_status(LED_NAME_LED1, LED_STATUS_ON);
	led_set_status(LED_NAME_LED2, LED_STATUS_ON);
	led_set_status(LED_NAME_LED3, LED_STATUS_ON);
	led_set_status(LED_NAME_LED4, LED_STATUS_ON);
	mdelay(1000);

	beep_set_status(BEEP_STATUS_ON);
	mdelay(200);
	led_set_status(LED_NAME_LED1, LED_STATUS_OFF);
	beep_set_status(BEEP_STATUS_OFF);
	mdelay(1000);

	beep_set_status(BEEP_STATUS_ON);
	mdelay(200);
	led_set_status(LED_NAME_LED2, LED_STATUS_OFF);
	beep_set_status(BEEP_STATUS_OFF);
	mdelay(1000);

	beep_set_status(BEEP_STATUS_ON);
	mdelay(200);
	led_set_status(LED_NAME_LED3, LED_STATUS_OFF);
	beep_set_status(BEEP_STATUS_OFF);
	mdelay(1000);

	beep_set_status(BEEP_STATUS_ON);
	mdelay(200);
	led_set_status(LED_NAME_LED4, LED_STATUS_OFF);
	beep_set_status(BEEP_STATUS_OFF);
	mdelay(2000);
																											// ϵͳ�����λ
	write32(phys_to_virt(S5P6818_SYS_PWRCONT), (read32(phys_to_virt(S5P6818_SYS_PWRCONT)) & ~(0x1 << 3)) | (0x1 << 3));
	write32(phys_to_virt(S5P6818_SYS_PWRMODE), (read32(phys_to_virt(S5P6818_SYS_PWRMODE)) & ~(0x1 << 12)) | (0x1 << 12));

	while (1)
	{
	}
}

static void gpiob30_interrupt_func(void *data)																// �жϷ�������VOL_UP_KEY -> GPIOB(30)������"+"
{
	request_irq("GPIOB31", gpiob31_interrupt_func, IRQ_TYPE_EDGE_FALLING, 0);								// ���ͬʱ��������"+"��������"��"��������GPIOB(31)��Ӧ���жϷ�����
	mdelay(200);
	key_status_change();																					// ���ݳ����������н����л���������
}

static void gpiob31_interrupt_func(void *data)																// �жϷ�������VOL_DOWN_KEY -> GPIOB(31)������"��"
{
	request_irq("GPIOB30", gpiob30_interrupt_func, IRQ_TYPE_EDGE_FALLING, 0);								// ���ͬʱ��������"+"��������"��"��������GPIOB(30)��Ӧ���жϷ�����
	mdelay(200);
	key_status_change();																					// �����������н����л���������
}
/*******************hardware control card end***********************/

/***************group order functions card start*************************/
//description: the core functions to realize stage and group order
void system_stage(int tag) 																					// ϵͳ�׶�ѡ����:1-�����׶Σ�2-�����׶Σ�3-��ȿ���׶Σ�0-�����׶�
{
	switch (tag)
	{

	case 1:								 																	// �����׶�01������һ�룬���һ�룬�������룺01
		beep_set_status(BEEP_STATUS_ON); 																	// ��������
		mdelay(1000);
		beep_set_status(BEEP_STATUS_OFF); 																	// �������ر�
		mdelay(1000);
		beep_set_status(BEEP_STATUS_ON); 																	// ��������
		mdelay(3000);
		beep_set_status(BEEP_STATUS_OFF);	 																// �������ر�
		mdelay(1000);
		break;

	case 2:								 																	// �����׶�10���������룬���һ�룬����һ�룺10
		beep_set_status(BEEP_STATUS_ON); 																	// ��������
		mdelay(3000);
		beep_set_status(BEEP_STATUS_OFF); 																	// �������ر�
		mdelay(1000);
		beep_set_status(BEEP_STATUS_ON); 																	// ��������
		mdelay(1000);
		beep_set_status(BEEP_STATUS_OFF); 																	// �������ر�
		mdelay(1000);
		break;

	case 3:								 																	// ��ȿ���׶�11���������룬���һ�룬�������룺11
		beep_set_status(BEEP_STATUS_ON); 																	// ��������
		mdelay(3000);
		beep_set_status(BEEP_STATUS_OFF); 																	// �������ر�
		mdelay(1000);
		beep_set_status(BEEP_STATUS_ON); 																	// ��������
		mdelay(3000);
		beep_set_status(BEEP_STATUS_OFF); 																	// �������ر�
		mdelay(1000);
		break;

	case 0:								 																	// �����׶�00������һ�룬���һ�룬����һ�룺00
		beep_set_status(BEEP_STATUS_ON); 																	// ��������
		mdelay(1000);
		beep_set_status(BEEP_STATUS_OFF); 																	// �������ر�
		mdelay(1000);
		beep_set_status(BEEP_STATUS_ON); 																	// ��������
		mdelay(1000);
		beep_set_status(BEEP_STATUS_OFF); 																	// �������ر�
		mdelay(1000);
		break;

	default:
		break;
	}
}

// author: 0000 0111B
// date: 2024/03/13
// ��ʾ��ŵĶ�����ת����ʽ����š�XX��ת����8λ��������ΪXXXX XXXXB��ģ��������"0"Ϊ����"0"ת����8λ������Ϊ0000 0000B���밴�ձ�����ʵ��ŶԱ����������޸�
void show_group_number()
{
	/********�����·������޸Ĵ��뼰ע�ͣ�ʵ������LED����ʾ������Ŷ�������ʽ��4λ�Ĺ���********/
	led_set_status(LED_NAME_LED1, LED_STATUS_OFF); 															// 0
	led_set_status(LED_NAME_LED2, LED_STATUS_OFF); 															// 0
	led_set_status(LED_NAME_LED3, LED_STATUS_OFF);  															// 0
	led_set_status(LED_NAME_LED4, LED_STATUS_OFF);  															// 0
	/********�����Ϸ������޸Ĵ��뼰ע�ͣ�ʵ������LED����ʾ������Ŷ�������ʽ��4λ�Ĺ���********/

	mdelay(3000);
	led_all_off(); 																							// LED��ȫ��
	mdelay(1000);  																							// �ӳ�һ��

	/********�����·������޸Ĵ��뼰ע�ͣ�ʵ������LED����ʾ������Ŷ�������ʽ��4λ�Ĺ���********/
	led_set_status(LED_NAME_LED1, LED_STATUS_OFF); 															// 0
	led_set_status(LED_NAME_LED2, LED_STATUS_ON); 															// 1
	led_set_status(LED_NAME_LED3, LED_STATUS_ON); 															// 1
	led_set_status(LED_NAME_LED4, LED_STATUS_ON); 															// 1
	/********�����Ϸ������޸Ĵ��뼰ע�ͣ�ʵ������LED����ʾ������Ŷ�������ʽ��4λ�Ĺ���********/

	mdelay(3000);
	led_all_off(); 																							// LED��ȫ��
	mdelay(1000);  																							// �ӳ�һ��

	beep_set_status(BEEP_STATUS_ON);   																		// ����������0.2�롢�ر�0.1�룻���ظ�һ�Σ������١��εΡ���������ʾ��ʾ��Ž���
	mdelay(200);
	beep_set_status(BEEP_STATUS_OFF);
	mdelay(100);
	beep_set_status(BEEP_STATUS_ON);
	mdelay(200);
	beep_set_status(BEEP_STATUS_OFF);
	mdelay(1000);
}

// author: 0111 1001B
// date: 2024/03/13
// ��ʾ�鳤����ƴ������ĸСд��ASCII�롣�鳤���ϡ�XXX����ƴ������ĸСд��X������ӦASCII��ΪXXXX XXXXB
void show_first_name_Lea()
{																											// ģ����"��"Ϊ������������ƴ������ĸСд��z������ӦASCII��Ϊ0111 1010B���밴�ձ����鳤��ʵ���϶Ա����������޸�
	/********�����·������޸Ĵ��뼰ע�ͣ�ʵ������LED����ʾ�鳤����ƴ������ĸСд��ASCII���4λ�Ĺ���********/
	led_set_status(LED_NAME_LED1, LED_STATUS_OFF); 															// 0
	led_set_status(LED_NAME_LED2, LED_STATUS_ON);  															// 1
	led_set_status(LED_NAME_LED3, LED_STATUS_ON);  															// 1
	led_set_status(LED_NAME_LED4, LED_STATUS_ON);  															// 1
	/********�����Ϸ������޸Ĵ��뼰ע�ͣ�ʵ������LED����ʾ�鳤����ƴ������ĸСд��ASCII���4λ�Ĺ���********/

	mdelay(3000);
	led_all_off(); 																							// LED��ȫ��
	mdelay(1000); 	 																						// �ӳ�һ��

	/********�����·������޸Ĵ��뼰ע�ͣ�ʵ������LED����ʾ�鳤����ƴ������ĸСд��ASCII���4λ�Ĺ���********/
	led_set_status(LED_NAME_LED1, LED_STATUS_ON);  															// 1
	led_set_status(LED_NAME_LED2, LED_STATUS_OFF); 															// 0
	led_set_status(LED_NAME_LED3, LED_STATUS_OFF);  															// 0
	led_set_status(LED_NAME_LED4, LED_STATUS_ON); 															// 1
	/********�����Ϸ������޸Ĵ��뼰ע�ͣ�ʵ������LED����ʾ�鳤����ƴ������ĸСд��ASCII���4λ�Ĺ���********/

	mdelay(3000);
	led_all_off(); 																							// LED��ȫ��
	mdelay(1000);  																							// �ӳ�һ��

	beep_set_status(BEEP_STATUS_ON); 																		// ����������0.2�롢�ر�0.1�룻���ظ�һ�Σ������١��εΡ���������ʾ�鳤��������
	mdelay(200);
	beep_set_status(BEEP_STATUS_OFF);
	mdelay(100);
	beep_set_status(BEEP_STATUS_ON);
	mdelay(200);
	beep_set_status(BEEP_STATUS_OFF);
	mdelay(1000);
}

// author: 0111 0111B
// date: 2024/03/13
// ��ʾ����Ա����ƴ������ĸСд��ASCII�롣����Ա���ϡ�XXX����ƴ������ĸСд��X������ӦASCII��ΪXXXX XXXXB
void show_first_name_req()
{
	/********�����·������д���뼰ע�ͣ�ʵ������LED����ʾ����Ա����ƴ������ĸСд��ASCII���4λ�Ĺ���********/
		led_set_status(LED_NAME_LED1, LED_STATUS_OFF); 															// 0
		led_set_status(LED_NAME_LED2, LED_STATUS_ON);  															// 1
		led_set_status(LED_NAME_LED3, LED_STATUS_ON);  															// 1
		led_set_status(LED_NAME_LED4, LED_STATUS_ON);  															// 1

	/********�����Ϸ������д���뼰ע�ͣ�ʵ������LED����ʾ����Ա����ƴ������ĸСд��ASCII���4λ�Ĺ���********/

	mdelay(3000);
	led_all_off(); 																							// LED��ȫ��
	mdelay(1000);  																							// �ӳ�һ��

	/********�����·������д���뼰ע�ͣ�ʵ������LED����ʾ����Ա����ƴ������ĸСд��ASCII���4λ�Ĺ���********/
		led_set_status(LED_NAME_LED1, LED_STATUS_OFF); 															// 0
		led_set_status(LED_NAME_LED2, LED_STATUS_ON);  															// 1
		led_set_status(LED_NAME_LED3, LED_STATUS_ON);  															// 1
		led_set_status(LED_NAME_LED4, LED_STATUS_ON);  															// 1
	/********�����Ϸ������д���뼰ע�ͣ�ʵ������LED����ʾ����Ա����ƴ������ĸСд��ASCII���4λ�Ĺ���********/

	mdelay(3000);
	led_all_off(); 																							// LED��ȫ��
	mdelay(1000);  																							// �ӳ�һ��

	beep_set_status(BEEP_STATUS_ON);  																		// ����������0.2�롢�ر�0.1�룻���ظ�һ�Σ������١��εΡ���������ʾ����Ա��������
	mdelay(200);
	beep_set_status(BEEP_STATUS_OFF);
	mdelay(100);
	beep_set_status(BEEP_STATUS_ON);
	mdelay(200);
	beep_set_status(BEEP_STATUS_OFF);
	mdelay(1000);
}

// author: 0111 0000B
// date: 2024/03/13
// ��ʾ��־Ա����ƴ������ĸСд��ASCII�롣��־Ա���ϡ�XXX����ƴ������ĸСд��X������ӦASCII��ΪXXXX XXXXB
void show_first_name_log()
{
	/********�����·������д���뼰ע�ͣ�ʵ������LED����ʾ��־Ա����ƴ������ĸСд��ASCII���4λ�Ĺ���********/
		led_set_status(LED_NAME_LED1, LED_STATUS_OFF); 															// 0
		led_set_status(LED_NAME_LED2, LED_STATUS_ON);  															// 1
		led_set_status(LED_NAME_LED3, LED_STATUS_ON);  															// 1
		led_set_status(LED_NAME_LED4, LED_STATUS_ON);  															// 1




	/********�����Ϸ������д���뼰ע�ͣ�ʵ������LED����ʾ��־Ա����ƴ������ĸСд��ASCII���4λ�Ĺ���********/

	mdelay(3000);
	led_all_off(); 																							// LED��ȫ��
	mdelay(1000);  																							// �ӳ�һ��

	/********�����·������д���뼰ע�ͣ�ʵ������LED����ʾ��־Ա����ƴ������ĸСд��ASCII���4λ�Ĺ���********/

	    led_set_status(LED_NAME_LED1, LED_STATUS_OFF); 															// 0
		led_set_status(LED_NAME_LED2, LED_STATUS_OFF);  															// 0
		led_set_status(LED_NAME_LED3, LED_STATUS_OFF);  															// 0
		led_set_status(LED_NAME_LED4, LED_STATUS_OFF);  															// 0



	/********�����Ϸ������д���뼰ע�ͣ�ʵ������LED����ʾ��־Ա����ƴ������ĸСд��ASCII���4λ�Ĺ���********/

	mdelay(3000);
	led_all_off(); 																							// LED��ȫ��
	mdelay(1000);  																							// �ӳ�һ��

	beep_set_status(BEEP_STATUS_ON);																		// ����������0.2�롢�ر�0.1�룻���ظ�һ�Σ������١��εΡ���������ʾ��־Ա��������
	mdelay(200);
	beep_set_status(BEEP_STATUS_OFF);
	mdelay(100);
	beep_set_status(BEEP_STATUS_ON);
	mdelay(200);
	beep_set_status(BEEP_STATUS_OFF);
	mdelay(1000);
}

// author: 0111 0111B
// date: 2024/03/13
// ��ʾ�Ų�Ա����ƴ������ĸ��Сд��ASCII�롣�Ų�Ա���ϡ�XXX����ƴ������ĸСд��X������ӦASCII��ΪXXXX XXXXB
void show_first_name_opt()
{
	/********�����·������д���뼰ע�ͣ�ʵ������LED����ʾ�Ų�Ա����ƴ������ĸСд��ASCII���4λ�Ĺ���********/
	        led_set_status(LED_NAME_LED1, LED_STATUS_OFF); 															// 0
			led_set_status(LED_NAME_LED2, LED_STATUS_ON);  															// 1
			led_set_status(LED_NAME_LED3, LED_STATUS_ON);  															// 1
			led_set_status(LED_NAME_LED4, LED_STATUS_ON);
	/********�����Ϸ������д���뼰ע�ͣ�ʵ������LED����ʾ�Ų�Ա����ƴ������ĸСд��ASCII���4λ�Ĺ���********/

	mdelay(3000);
	led_all_off(); 																							// LED��ȫ��
	mdelay(1000);  																							// �ӳ�һ��

	/********�����·������д���뼰ע�ͣ�ʵ������LED����ʾ�Ų�Ա����ƴ������ĸСд��ASCII���4λ�Ĺ���********/
	        led_set_status(LED_NAME_LED1, LED_STATUS_OFF); 															// 0
			led_set_status(LED_NAME_LED2, LED_STATUS_ON);  															// 1
			led_set_status(LED_NAME_LED3, LED_STATUS_ON);  															// 1
			led_set_status(LED_NAME_LED4, LED_STATUS_ON);
	/********�����Ϸ������д���뼰ע�ͣ�ʵ������LED����ʾ�Ų�Ա����ƴ������ĸСд��ASCII���4λ�Ĺ���********/

	mdelay(3000);
	led_all_off(); 																							// LED��ȫ��
	mdelay(1000);  																							// �ӳ�һ��

	beep_set_status(BEEP_STATUS_ON);																		// ����������0.2�롢�ر�0.1�룻���ظ�һ�Σ������١��εΡ���������ʾ�Ų�Ա��������
	mdelay(200);
	beep_set_status(BEEP_STATUS_OFF);
	mdelay(100);
	beep_set_status(BEEP_STATUS_ON);
	mdelay(200);
	beep_set_status(BEEP_STATUS_OFF);
	mdelay(1000);
}

// author: 0111 0111B
// date: 2024/03/13
// ��ʾչʾԱ����ƴ������ĸСд��ASCII�롣չʾԱ���ϡ�XXX����ƴ������ĸСд��X������ӦASCII��ΪXXXX XXXXB
void show_first_name_sho()
{
	/********�����·������д���뼰ע�ͣ�ʵ������LED����ʾչʾԱ����ƴ������ĸСд��ASCII���4λ�Ĺ���********/
	        led_set_status(LED_NAME_LED1, LED_STATUS_OFF); 															// 0
			led_set_status(LED_NAME_LED2, LED_STATUS_ON);  															// 1
			led_set_status(LED_NAME_LED3, LED_STATUS_ON);  															// 1
			led_set_status(LED_NAME_LED4, LED_STATUS_ON);

	/********�����Ϸ������д���뼰ע�ͣ�ʵ������LED����ʾչʾԱ����ƴ������ĸСд��ASCII���4λ�Ĺ���********/

	mdelay(3000);
	led_all_off(); 																							// LED��ȫ��
	mdelay(1000);  																							// �ӳ�һ��

	/********�����·������д���뼰ע�ͣ�ʵ������LED����ʾչʾԱ����ƴ������ĸСд��ASCII���4λ�Ĺ���********/
        	led_set_status(LED_NAME_LED1, LED_STATUS_OFF); 															// 0
			led_set_status(LED_NAME_LED2, LED_STATUS_ON);  															// 1
			led_set_status(LED_NAME_LED3, LED_STATUS_ON);  															// 1
			led_set_status(LED_NAME_LED4, LED_STATUS_ON);

	/********�����Ϸ������д���뼰ע�ͣ�ʵ������LED����ʾչʾԱ����ƴ������ĸСд��ASCII���4λ�Ĺ���********/

	mdelay(3000);
	led_all_off(); 																							// LED��ȫ��
	mdelay(1000);  																							// �ӳ�һ��

	beep_set_status(BEEP_STATUS_ON);																		// ����������0.2�롢�ر�0.1�룻���ظ�һ�Σ������١��εΡ���������ʾչʾԱ��������
	mdelay(200);
	beep_set_status(BEEP_STATUS_OFF);
	mdelay(100);
	beep_set_status(BEEP_STATUS_ON);
	mdelay(200);
	beep_set_status(BEEP_STATUS_OFF);
	mdelay(1000);
}

void interrupt_group_order()																				// ���ݰ������ζ�����Ա����־Ա���Ų�Ա��չʾԱ���е���
{
	u32_t VOL_UP_STAT = gpio_get_value(S5P6818_GPIOB(30));													// ��ȡ����"+"���İ���״̬���ж��Ƿ��£���ȡֵΪ0��Ϊ�����Ѱ��£�ֵΪ1��Ϊ����δ����
	u32_t VOL_DOWN_STAT = gpio_get_value(S5P6818_GPIOB(31));												// ��ȡ����"��"���İ���״̬���ж��Ƿ��£���ȡֵΪ0��Ϊ�����Ѱ��£�ֵΪ1��Ϊ����δ����

	if (VOL_UP_STAT == 0 && VOL_DOWN_STAT == 0)
	{

		show_first_name_opt();																				// �Ų�Ա����
		show_first_name_sho();																				// չʾԱ����

		beep_set_status(BEEP_STATUS_ON);																	// �����̴ٵķ��������조�εεΡ�����ʾ���е�������
		mdelay(200);
		beep_set_status(BEEP_STATUS_OFF);
		mdelay(100);
		beep_set_status(BEEP_STATUS_ON);
		mdelay(200);
		beep_set_status(BEEP_STATUS_OFF);
		mdelay(100);
		beep_set_status(BEEP_STATUS_ON);
		mdelay(200);
		beep_set_status(BEEP_STATUS_OFF);
		mdelay(3000);

		key_st = STAGE_CHANGE;																				// �������������������л�Ϊ���׶��л���
	}
	else if (VOL_UP_STAT == 0 && VOL_DOWN_STAT != 0)
	{
		show_first_name_log();																				// ��־Ա����
	}
	else if (VOL_UP_STAT != 0 && VOL_DOWN_STAT == 0)
	{
		show_first_name_req();																				// ����Ա����
	}
	else
	{
	}
}

void interrupt_stage_change()																				// ���ݰ����л���ͬstage
{
	u32_t VOL_UP_STAT = gpio_get_value(S5P6818_GPIOB(30));    												// ��ȡ����"+"���İ���״̬���ж��Ƿ��£���ȡֵΪ0��Ϊ�����Ѱ��£�ֵΪ1��Ϊ����δ����
	u32_t VOL_DOWN_STAT = gpio_get_value(S5P6818_GPIOB(31));												// ��ȡ����"��"���İ���״̬���ж��Ƿ��£���ȡֵΪ0��Ϊ�����Ѱ��£�ֵΪ1��Ϊ����δ����

	if (VOL_UP_STAT == 0 && VOL_DOWN_STAT == 0)																// stage2����ȿ���׶�
	{
		system_stage(3);																					// �ȴ�״̬

		led_all_on(); 																						// ������LED��
		while (1)	  																						// ÿ���3�룬ѭ��һ�Σ����������������������εεΡ�
		{
			beep_set_status(BEEP_STATUS_ON);
			mdelay(200);
			beep_set_status(BEEP_STATUS_OFF);
			mdelay(100);
			beep_set_status(BEEP_STATUS_ON);
			mdelay(200);
			beep_set_status(BEEP_STATUS_OFF);
			mdelay(100);
			beep_set_status(BEEP_STATUS_ON);
			mdelay(200);
			beep_set_status(BEEP_STATUS_OFF);
			mdelay(3000);
		}


		// system_stage(0);																					// stage3�������׶�
		// tester_reset();																					// ���������LED�Ƶ���ʱ����ϵͳ������λ
	}
	else if (VOL_UP_STAT == 0 && VOL_DOWN_STAT != 0)
	{
		system_stage(2);																					// stage1�������׶�

		show_group_number();																				// ��ʾ���
		show_first_name_Lea(); 																				// �鳤����
																											// ��Ա����
		key_st = ORDER;																						// ���������л�Ϊ��������
	}
	else if (VOL_UP_STAT != 0 && VOL_DOWN_STAT == 0)
	{

		system_stage(1); 																					// stage0�������׶�01
	}
	else
	{
	}
}

void key_status_change()																					// ����ȫ�ֱ���key_st��ֵ�л���������Ϊ���׶��л����򡰵�����
{
	switch (key_st)
	{
	case STAGE_CHANGE:																						// ���������л�Ϊ���׶��л���

		interrupt_stage_change();
		break;
	case ORDER:																								// ���������л�Ϊ��������
		interrupt_group_order();
		break;
	}
}
/*******************group order functions card end***********************/

/*******************main function card start*********************/
//description: the main function for main.c's calling and calling other function
int tester_key_led_beep(int argc, char *argv[])																// ͨ�������жϷ�ʽ����Ⱥ���������
{																											// Q0
	init_stat(); 																							// ��ʼ��ϵͳ״̬���ĸ�LED��ȫ�������������죬����3�룻֮��LED��ȫ�𣬷������رգ�����1��
	gpio_set_cfg(S5P6818_GPIOB(30), 1);																		// ��ʼ��VOL_UP_KEY������Ӧ��GPIOB(30)
	gpio_set_pull(S5P6818_GPIOB(30), GPIO_PULL_UP);
	gpio_direction_input(S5P6818_GPIOB(30));
	request_irq("GPIOB30", gpiob30_interrupt_func, IRQ_TYPE_EDGE_FALLING, 0);								// ��������"+"����Ӧ���жϷ��������½��ش����ж�

	gpio_set_cfg(S5P6818_GPIOB(31), 1);																		// ��ʼ��VOL_DOWN_KEY������Ӧ��GPIOB(31)
	gpio_set_pull(S5P6818_GPIOB(31), GPIO_PULL_UP);
	gpio_direction_input(S5P6818_GPIOB(31));
	request_irq("GPIOB31", gpiob31_interrupt_func, IRQ_TYPE_EDGE_FALLING, 0);								// ��������"��"����Ӧ���жϷ��������½��ش����ж�

	while (1)
	{
	}

	return 0;
}
/*******************main function card end***********************/

/*********************��  ��  ��  ��  ��  ��********************/
