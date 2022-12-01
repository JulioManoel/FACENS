using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Move : MonoBehaviour
{
    public float _velocidadeAndando = 10.0f;
    public float _velocidadeCorrendo = 20.0f;
	public float _girar = 60.0f;

    float _velocidade = 0;
    float _anim = 0;

    private Animator _animator;

    private void Awake() {
        _animator = GetComponent<Animator>();
    }

    void Update()
    {
        if(Input.GetKey(KeyCode.LeftShift)) 
        {
            _velocidade = _velocidadeCorrendo;
            _anim = 2;
        }
        else
        {
            _velocidade = _velocidadeAndando;
            _anim = 1;
        } 

        float translate = (Input.GetAxis ("Vertical") * _velocidade) * Time.deltaTime;
		float rotate = (Input.GetAxis ("Horizontal") * _girar) * Time.deltaTime;
		transform.Translate (0, 0, translate);
		transform.Rotate (0, rotate, 0);

        _animator.SetFloat("Speed", Input.GetAxis ("Vertical") * _anim);
    }
}
