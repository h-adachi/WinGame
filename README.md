# WinGame

# 概要
* ゲーム作成用のテンプレート
  
  
# 対象
* Windows ユーザー
* Visutal Studio
* デバイスコンテキスト(HDC)の知識  
  https://msdn.microsoft.com/ja-jp/library/cc428272.aspx
  
  
# 実施している事
* Windowsの生成
* ダブルバッファ
* 入力キーの管理
* Scene管理
  
  
# 使い方
## Scene制御
* ISceneを継承したクラスを作成し実装する
* EnterでScene初回に実施すべき事
* UpdateでScene内で毎フレーム実施すべき事
* ExitでScene終了時に実施すべき事

で実現する
  
  
## キー制御
* InputListに対してアクションと仮想キーを登録する
* 登録したアクションからInputを参照出来る
* isPressで正に今押されたか否か
* isDownで押されているか否か
* isUpで離されているか否か

を取得する
