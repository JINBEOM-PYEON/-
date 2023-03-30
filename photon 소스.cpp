using UnityEngine;
using Photon.Pun;

public class PhotonManager : MonoBehaviourPunCallbacks
{
    public void ConnectToServer()
    {
        if (!PhotonNetwork.IsConnected)
        {
            PhotonNetwork.ConnectUsingSettings();
        }
    }

    public void JoinRoom(string roomName)
    {
        PhotonNetwork.JoinRoom(roomName);
    }

    public void CreateRoom(string roomName)
    {
        PhotonNetwork.CreateRoom(roomName);
    }

    public override void OnConnectedToMaster()
    {
        Debug.Log("Connected to Photon server");
    }

    public override void OnDisconnected(DisconnectCause cause)
    {
        Debug.Log("Disconnected from Photon server: " + cause.ToString());
    }

    public override void OnJoinedRoom()
    {
        Debug.Log("Joined room: " + PhotonNetwork.CurrentRoom.Name);
    }

    public override void OnCreateRoomFailed(short returnCode, string message)
    {
        Debug.Log("Failed to create room: " + message);
    }

    public override void OnJoinRoomFailed(short returnCode, string message)
    {
        Debug.Log("Failed to join room: " + message);
    }
}

using UnityEngine;
using UnityEngine.UI;

public class ConnectScene : MonoBehaviour
{
    public InputField nicknameInput;
    public Dropdown characterDropdown;

    public void ConnectToServer()
    {
        PhotonManager photonManager = FindObjectOfType<PhotonManager>();
        photonManager.ConnectToServer();
    }

    public void JoinRoom()
    {
        PhotonManager photonManager = FindObjectOfType<PhotonManager>();
        string roomName = "Room 1";
        photonManager.JoinRoom(roomName);
    }

    public void CreateRoom()
    {
        PhotonManager photonManager = FindObjectOfType<PhotonManager>();
        string roomName = "Room 1";
        photonManager.CreateRoom(roomName);
    }
}

using UnityEngine;
using Photon.Pun;

public class PhotonConnect : MonoBehaviourPunCallbacks
{
    private string nickname;
    private int characterIndex;

    void Start()
    {
        PhotonManager photonManager = FindObjectOfType<PhotonManager>();
        nickname = photonManager.GetNickname();
        characterIndex = photonManager.GetCharacterIndex();

        PhotonNetwork.ConnectUsingSettings();
    }

    public override void OnConnectedToMaster()
    {
        Debug.Log("Connected to Photon server");
        PhotonNetwork.LocalPlayer.NickName = nickname;
        PhotonNetwork.JoinRandomRoom();
    }

    public override void OnDisconnected(DisconnectCause cause)
    {
        Debug.Log("Disconnected from Photon server: " + cause.ToString());
    }

    public override void OnJoinRandomFailed(short returnCode, string message)
    {
        Debug.Log("Failed to join random room: " + message);
        PhotonNetwork.CreateRoom(null, new RoomOptions{ MaxPlayers = 4 });
    }

    public override void OnJoinedRoom()
    {
        Debug.Log("Joined room: " + PhotonNetwork.CurrentRoom.Name);
        SpawnPlayer();
    }

    void SpawnPlayer()
    {
        Vector3 spawnPosition = new Vector3(0f, 0.5f, 0f);
        PhotonNetwork.Instantiate("Player" + characterIndex.ToString(), spawnPosition, Quaternion.identity);
    }
}

위에서 작성한 Photon 스크립트를 실제 유니티에 적용하기 위해서는 몇 가지 과정이 필요합니다.

Photon PUN 2 패키지 설치하기
Photon PUN을 사용하기 위해서는 먼저 Photon PUN 2 패키지를 Unity Package Manager에서 설치해야 합니다.이를 위해서는 Unity Editor에서 다음과 같은 단계를 따르면 됩니다.
Window->Package Manager 메뉴 선택
Package Manager 창에서 "+" 버튼을 클릭하여 패키지 추가
"Photon Unity Networking 2" 검색 후 설치
Photon App ID 설정하기
Photon PUN을 사용하려면 Photon Cloud Dashboard에서 App ID를 발급받아야 합니다.발급받은 App ID는 Unity Editor에서 PhotonServerSettings 스크립트에서 설정해줘야 합니다.

스크립트 구현하기
위에서 작성한 Photon 스크립트를 Unity Editor에서 적절한 폴더에 생성하고, 필요에 따라 다른 스크립트와 연결해줘야 합니다.

씬 구성하기
멀티플레이어 게임을 만들기 위해서는 여러 씬을 구성해야 합니다.이때 각 씬에서 Photon 스크립트를 사용하여 연결하고, 캐릭터를 생성하도록 구현해야 합니다.

빌드 및 실행하기
위의 모든 과정을 완료하면 Unity Editor에서 게임을 빌드하고 실행할 수 있습니다.이때 Photon 서버와의 연결을 확인하고, 멀티플레이어 게임이 잘 동작하는지 확인해야 합니다.