# Chrome Extension Walkthrough: YouTube German–English Subtitle Translator

This document explains how Chrome extensions are structured, and then walks
through every file in this extension line-by-line so you can understand how
it works and modify it yourself.

---

## 1. What is a Chrome Extension?

A Chrome extension is a small software program that customizes the browsing
experience. It is built with standard web technologies (HTML, CSS,
JavaScript) and runs inside Chrome.

Extensions work because Chrome gives them special permissions that normal
websites do not have:

| Normal Website | Chrome Extension |
|---|---|
| Can read/modify only its own page | Can read/modify any page matching declared URLs |
| Cannot access Chrome APIs | Can use `chrome.*` APIs (tabs, storage, runtime, etc.) |
| Runs only when its tab is open | Background service worker can run across tabs |

---

## 2. The Anatomy of an Extension

Every extension needs at least two files:

```
yt-subtitle-translation/
├── manifest.json      # The "manifest" — tells Chrome what this extension is
├── content.js         # Code injected into web pages (YouTube)
├── background.js      # Background service worker (long-lived logic)
└── explanation.md     # This file
```

### 2.1 manifest.json

The manifest is the heart of every extension. It is a JSON file that declares:

*   **manifest_version** — Must be `3` (the current version).
*   **name / version / description** — Human-readable metadata.
*   **permissions** — What the extension is allowed to do (e.g. `activeTab`).
*   **content_scripts** — Which JS files to inject into which URLs.
*   **background** — Which file runs as the service worker.

Without a manifest, Chrome has no idea your directory is an extension.

### 2.2 Content Scripts

A **content script** runs in the context of a web page. It sees the same DOM
that the user sees, can click buttons, read text, and control `<video>`
elements. However, it **cannot** call Chrome APIs directly (no
`chrome.tabs`, no `chrome.storage`).

Content scripts are declared in `manifest.json` under `content_scripts`.
Chrome automatically injects them into matching pages.

### 2.3 Background Scripts (Service Workers)

A **background script** (service worker in MV3) lives independently of any
single tab. It can use all Chrome APIs and handles events like "extension
icon clicked" or "message from content script".

In our simple extension, most logic lives in the content script, so the
background script is mostly a placeholder to show you where background
logic would go.

---

## 3. File-by-File Walkthrough

### 3.1 manifest.json

```json
{
  "manifest_version": 3,
  "name": "YouTube DE-EN Subtitle Translator",
  "version": "1.0.0",
  "description": "Hover over German subtitles to pause the video and see the English translation.",
  "permissions": ["activeTab"],
  "content_scripts": [
    {
      "matches": ["https://www.youtube.com/*", "https://youtube.com/*"],
      "js": ["content.js"],
      "run_at": "document_idle"
    }
  ],
  "background": {
    "service_worker": "background.js"
  }
}
```

*   `"matches"`: Tells Chrome to inject `content.js` into every YouTube page.
*   `"run_at": "document_idle"`: Inject after the page has finished loading.
*   `"background.service_worker"`: Registers `background.js` as the service worker.

### 3.2 content.js — The Main Logic

This is the most important file. Here is what it does, section by section:

#### A. Dictionary (lines ~20-60)

```javascript
const DICTIONARY = {
  "die": "the",
  "der": "the",
  ...
};
```

A small hard-coded German → English lookup table. You can add more words
here, or later replace it with a call to an online dictionary API.

#### B. `translateWord(word)`

Cleans punctuation, lower-cases the word, and looks it up in `DICTIONARY`.
Returns `null` if the word is not found.

#### C. Tooltip system (`ensureTooltip`, `showTooltip`, `hideTooltip`)

Creates a small `<div>` that follows the mouse and shows the translation.
`pointerEvents: "none"` ensures clicks pass through the tooltip to the page
underneath.

#### D. Video control (`pauseVideo`, `resumeVideo`)

Finds the `<video>` element on the page and calls `.pause()`. YouTube
usually has exactly one `<video>` tag per page.

#### E. Caption detection (`isCaptionElement`)

Walks up the DOM tree from the hovered element and checks if any ancestor
has a class name containing "caption", "subtitle", "ytp-caption", or
"captions". This is how we know the mouse is over a subtitle and not over
some other part of the page.

*Note: YouTube changes its class names occasionally. If hover detection
stops working, inspect the subtitle element in Chrome DevTools and update
the regex in `isCaptionElement`.*

#### F. Event handlers (`onMouseOver`, `onMouseOut`)

*   `onMouseOver`: If we are over a caption element, look up the word,
    pause the video, and show the tooltip.
*   `onMouseOut`: Hide the tooltip.

Both use the **capture phase** (`true` as the third argument to
`addEventListener`) so our code runs before any YouTube internal handler
can stop the event from propagating.

### 3.3 background.js — Background Service Worker

Currently just logs a startup message. The commented-out sections show
patterns you will use as your extension grows:

*   `chrome.action.onClicked` — react to the extension icon being clicked.
*   `chrome.runtime.onMessage` — receive messages from content scripts.
*   `chrome.storage.sync.get/set` — persist user settings across sessions.

---

## 4. How to Load the Extension in Chrome

1. Open Chrome and go to `chrome://extensions/`
2. Toggle **Developer mode** (top-right corner) to ON.
3. Click **Load unpacked**.
4. Select the folder: `/home/kumar/playground/yt-subtitle-translation/`
5. The extension appears in your list. Open YouTube, enable German subtitles
   on any video, and hover over German words.

---

## 5. Ideas to Extend This Extension

Here are small, self-contained upgrades you can try:

| Idea | What to change |
|---|---|
| **Resume video on mouse-out** | Uncomment `resumeVideo()` inside `onMouseOut` in `content.js`. |
| **Add more words** | Add entries to the `DICTIONARY` object in `content.js`. |
| **Persist dictionary in storage** | Use `chrome.storage.sync` in `background.js` to store/retrieve the dictionary. |
| **Auto-resume after 3 seconds** | Call `setTimeout(resumeVideo, 3000)` after pausing. |
| **Popup UI** | Add `default_popup: "popup.html"` to manifest, create `popup.html` with settings. |
| **Fetch translations online** | Replace `DICTIONARY` lookup with `fetch()` to a translation API. |

---

## 6. Debugging Tips

1. **Open DevTools on the YouTube page** — press F12. Content script logs
   appear here (`console.log` from `content.js`).
2. **Open DevTools for the background service worker** — go to
   `chrome://extensions/`, click "Inspect views: background page" for your
   extension.
3. **Check the Elements panel** — inspect a subtitle word to see its class
   names and adjust `isCaptionElement` accordingly.

---

## Summary

You now have a minimal, working Chrome extension that:

1. Injects a content script into YouTube pages.
2. Detects when you hover over German subtitle words.
3. Pauses the video.
4. Shows an English translation tooltip.

This is the foundation. From here you can add more words, fetch translations
from the internet, add a settings popup, or support more languages. Happy coding!
