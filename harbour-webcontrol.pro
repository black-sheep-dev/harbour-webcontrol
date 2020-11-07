TEMPLATE = subdirs

SUBDIRS += \
    app
    
OTHER_FILES += $$files(rpm/*)

webfrontend.path = /usr/share/$$TARGET/frontend
webfrontend.files = web-frontend/dist/*
INSTALLS += webfrontend
