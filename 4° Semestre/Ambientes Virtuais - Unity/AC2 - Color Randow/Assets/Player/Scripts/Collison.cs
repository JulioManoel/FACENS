using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Collison : MonoBehaviour
{
    Transform respaw;
    Vector3 pos;
    Quaternion rot;

    // Start is called before the first frame update
    void Start()
    {
        respaw = GetComponent<Transform>();
		pos = new Vector3();
		pos = respaw.position;
		rot = respaw.rotation;
    }

    // Update is called once per frame
    void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.name == "GameOver")
        {
            positionRest();
            SceneManager.LoadScene("SampleScene", LoadSceneMode.Single);
        }
	}

    public void positionRest() {
        respaw.position = pos;
		respaw.rotation = rot;
    }
}
