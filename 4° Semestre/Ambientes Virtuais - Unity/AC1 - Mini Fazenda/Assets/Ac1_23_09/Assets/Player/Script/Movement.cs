using UnityEngine;

public class Movement : MonoBehaviour
{
    public float movementSpeed = 10f;
    public Animator animator; //Função para colocar a animação de andar

    //Void para inicializar com o mouse fixo e invisivel sobre o personagem
    void Start() {
        Cursor.visible = false;
        Cursor.lockState = CursorLockMode.Locked;
    }
    

    private void Update()
    {
        //Input de animação
        float xAxis = Input.GetAxis("Horizontal");
        float zAxis = Input.GetAxis("Vertical");
        Vector3 direction = new Vector3(xAxis, 0, zAxis);

        Move(direction);

        //Rotacionar o personagem de acordo com o mouse
        transform.Rotate(new Vector3(0, (Input.GetAxis("Mouse X")*60.0f)*Time.deltaTime,0 ));

        //If para controle da animação (Animar apenas quando começar a mover)
        if(direction.magnitude > 0){
            animator.SetBool("Andando", true);
        }
        else{
            animator.SetBool("Andando", false);
        }
    }

    //Funcao para gerar movimento
    public void Move(Vector3 direction)
    {
        transform.Translate(direction * movementSpeed * Time.deltaTime);
    }
}
