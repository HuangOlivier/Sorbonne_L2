<?php
/// Fermeture de la connexion POP3.
/// Neutraliser par @ le message d'erreur eventuel
/// (si le serveur a deja rompu la connexion ce n'est pas grave)

include "requeter_en_pop.php";

function fermer_session_pop ($sock)
{
  requeter_en_pop($sock, "QUIT");
  @fclose($sock);
}
?>