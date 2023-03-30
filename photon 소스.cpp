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

������ �ۼ��� Photon ��ũ��Ʈ�� ���� ����Ƽ�� �����ϱ� ���ؼ��� �� ���� ������ �ʿ��մϴ�.

Photon PUN 2 ��Ű�� ��ġ�ϱ�
Photon PUN�� ����ϱ� ���ؼ��� ���� Photon PUN 2 ��Ű���� Unity Package Manager���� ��ġ�ؾ� �մϴ�.�̸� ���ؼ��� Unity Editor���� ������ ���� �ܰ踦 ������ �˴ϴ�.
Window->Package Manager �޴� ����
Package Manager â���� "+" ��ư�� Ŭ���Ͽ� ��Ű�� �߰�
"Photon Unity Networking 2" �˻� �� ��ġ
Photon App ID �����ϱ�
Photon PUN�� ����Ϸ��� Photon Cloud Dashboard���� App ID�� �߱޹޾ƾ� �մϴ�.�߱޹��� App ID�� Unity Editor���� PhotonServerSettings ��ũ��Ʈ���� ��������� �մϴ�.

��ũ��Ʈ �����ϱ�
������ �ۼ��� Photon ��ũ��Ʈ�� Unity Editor���� ������ ������ �����ϰ�, �ʿ信 ���� �ٸ� ��ũ��Ʈ�� ��������� �մϴ�.

�� �����ϱ�
��Ƽ�÷��̾� ������ ����� ���ؼ��� ���� ���� �����ؾ� �մϴ�.�̶� �� ������ Photon ��ũ��Ʈ�� ����Ͽ� �����ϰ�, ĳ���͸� �����ϵ��� �����ؾ� �մϴ�.

���� �� �����ϱ�
���� ��� ������ �Ϸ��ϸ� Unity Editor���� ������ �����ϰ� ������ �� �ֽ��ϴ�.�̶� Photon �������� ������ Ȯ���ϰ�, ��Ƽ�÷��̾� ������ �� �����ϴ��� Ȯ���ؾ� �մϴ�.