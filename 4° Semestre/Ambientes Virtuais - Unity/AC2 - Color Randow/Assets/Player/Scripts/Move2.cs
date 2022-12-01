using System.Collections;
using System.Collections.Generic;
using UnityEngine;



public class Move2 : MonoBehaviour{
	
	public GameObject _foward;
	public GameObject _back;
	public GameObject _Right;
	public GameObject _Left;
	
	Button _componentForward;
	Button _componentBack;
	Button _componentRight;
	Button _componentLeft;

    public float _velocidade = 20.0f;
	public float _girar = 80.0f;
	public int valorFuncao;

	

    // Start is called before the first frame update
    void Start()
    {
		_componentForward = _foward.GetComponent<Button> ();
		_componentBack = _back.GetComponent<Button>();
		_componentRight = _Right.GetComponent<Button>();
		_componentLeft = _Left.GetComponent<Button> ();
    }

    // Update is called once per frame
    void Update()
    {
		if(_componentBack.input == 1){
			Back();
			float translate = ((_componentBack.input * valorFuncao) * _velocidade) * Time.deltaTime;
			transform.Translate (0, 0, translate);
		}

		if(_componentForward.input == 1){
			Forward();
			float translate = ((_componentForward.input * valorFuncao) * _velocidade) * Time.deltaTime;
			transform.Translate (0, 0, translate);
		}

		if(_componentRight.input == 1){
			Right();
			float rotate = ((_componentRight.input * valorFuncao) * _girar) * Time.deltaTime;
			transform.Rotate (0, rotate, 0);
		}

		if(_componentLeft.input == 1){
			Left();
			float rotate = ((_componentLeft.input * valorFuncao) * _girar) * Time.deltaTime;
			transform.Rotate (0, rotate, 0);
		}
    }

	//Utilizar do 1 e -1 para simular as setas do teclado
	//Sendo para a movimentação o translate e para rotação o rotate
	public void Forward (){
		valorFuncao = 1;
	}

	public void Back(){
		valorFuncao = -1;
	}

	public void Left(){
		//Da mesma forma, utilizar o range de -1 e 1 para diferenciar esquerdo e direito.
		valorFuncao = -1;
	}

	public void Right(){
		valorFuncao = 1;
	}
}
