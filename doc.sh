#!/bin/bash
# =========================================
# 📘 Script de génération de documentation
# =========================================

# Arrêt en cas d’erreur
set -e

# Vérifie la présence du fichier Doxyfile
if [ ! -f "Doxyfile" ]; then
  echo "❌ Fichier Doxyfile introuvable. Crée-le avec : doxygen -g"
  exit 1
fi

# Génération de la documentation
echo "🧩 Génération de la documentation Doxygen..."
doxygen

# Vérifie si le dossier html a été généré
if [ ! -d "html" ]; then
  echo "❌ Erreur : le dossier html n’a pas été généré."
  exit 1
fi

# Lancement d’un serveur web local
echo "🌐 Serveur web local lancé sur http://localhost:8000"
python3 -m http.server -d html
