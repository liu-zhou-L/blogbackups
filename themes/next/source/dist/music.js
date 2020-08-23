const ap = new APlayer({
    container: document.getElementById('aplayer'),
    fixed: true,
    autoplay: false,
    audio: [
      {
        name: '神经病之歌',
        artist: '洛天依 & 言和',
        url: '/music/神经病之歌.mp3',
        cover: 'https://p3fx.kgimg.com/stdmusic/20170615/20170615004141842583.jpg',
      },
      {
        name: '狐言',
        artist: '洛天依 & 河图',
        url: '/music/狐言.mp3',
        cover: 'https://p3fx.kgimg.com/stdmusic/20160601/20160601163630604616.jpg',
      },
      {
        name: '达拉崩吧',
        artist: '洛天依 & 言和',
        url: '/music/达拉崩吧.mp3',
        cover: 'https://imgessl.kugou.com/uploadpic/softhead/400/20160722/20160722185354390495.jpg',
      }
    ]
});